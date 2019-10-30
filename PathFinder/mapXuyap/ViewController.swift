//
//  ViewController.swift
//  mapXuyap
//
//  Created by Mykyta DANYLCHENKO on 10/12/19.
//  Copyright © 2019 Mykyta DANYLCHENKO. All rights reserved.
//

import UIKit
import MapKit
import GoogleMaps
import GoogleMapsDirections
import GooglePlacesAPI
import GooglePlaces

class ViewController: UIViewController, GMSMapViewDelegate {
    
    let apiKey = "AIzaSyAa6yETW8PNZa4uvNxskcP4v_VajNMjw4A"
    let defaultLocation = CLLocation(latitude: 50.4688257, longitude: 30.4621588)
    
    var origin = myPlace()
    var destination = myPlace()
    var locationManager = CLLocationManager()
    var routePolyline: GMSPolyline?
    var duration: String? = "Unknown"
    var distance: String? = "Unknown"
    
    var zoomLevel: Float = 15.0
    
    @IBOutlet weak var originTextField: UITextField!
    @IBOutlet weak var destinationTextField: UITextField!
    
    @IBOutlet var mapView: GMSMapView!
    var originMarker: GMSMarker?
    var destinationMarker: GMSMarker?

    
    override func viewDidLoad() {
        super.viewDidLoad()
        ///set background
        view.backgroundColor = #colorLiteral(red: 0.8039215803, green: 0.8039215803, blue: 0.8039215803, alpha: 1)
        // Initialize the location manager.
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.requestAlwaysAuthorization()
        //        locationManager.requestWhenInUseAuthorization()
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.startMonitoringSignificantLocationChanges()
        locationManager.distanceFilter = 50
        locationManager.startUpdatingLocation()
        // Create a map.
        let camera = GMSCameraPosition.camera(withLatitude: defaultLocation.coordinate.latitude,
                                              longitude: defaultLocation.coordinate.longitude, zoom: zoomLevel)
        mapView.camera = camera
        mapView.delegate = self
        mapView.settings.myLocationButton = true
        mapView.settings.compassButton = true
        mapView.settings.zoomGestures = true
        mapView.isMyLocationEnabled = true
        mapView.accessibilityElementsHidden = false
    }

    @IBAction func informationButtonPressed(_ sender: UIButton) {
        
        if origin.textField != "" && destination.textField != "" {
            let actionSheet = UIAlertController(title: "Information", message: "Route request from \(origin.textField) to \(destination.textField)", preferredStyle: UIAlertController.Style.actionSheet)
            let alert1 = UIAlertAction(title:  "duaration is \(duration ?? "Unknown")", style: UIAlertAction.Style.default)  { (alertAction) ->  Void in }
            let alert2 = UIAlertAction(title: "distance is \(distance ?? "Unknown")", style: UIAlertAction.Style.default) { (alertAction) ->  Void in }
            let alert3 = UIAlertAction(title: "Looks cool right?)", style: UIAlertAction.Style.default) { (alertAction) ->  Void in }
                let cancelAction = UIAlertAction(title: "Close", style: UIAlertAction.Style.cancel) { (UIAlertAction) -> Void in }
            actionSheet.addAction(cancelAction)
            actionSheet.addAction(alert1)
            actionSheet.addAction(alert2)
            actionSheet.addAction(alert3)
            present(actionSheet, animated: true, completion: nil)
        } else {
            
            let actionSheet = UIAlertController(title: "Information", message: "Route request summary:", preferredStyle: UIAlertController.Style.actionSheet)
            let alert4 = UIAlertAction(title:  "Try to make one.", style: UIAlertAction.Style.default) { (alertAction) ->  Void in }
            let cancelAction = UIAlertAction(title: "Close", style: UIAlertAction.Style.cancel) { (UIAlertAction) -> Void in }
            actionSheet.addAction(alert4)
            actionSheet.addAction(cancelAction)
            present(actionSheet, animated: true, completion: nil)
        }
    }
    
    
    
    @IBAction func mapTypePressed(_ sender: UIButton) {
        let actionSheet = UIAlertController(title: "Map Types", message: "Select map type:", preferredStyle: UIAlertController.Style.actionSheet)
        let normalMapTypeAction = UIAlertAction(title: "Normal", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .normal
        }
        let terrainMapTypeAction = UIAlertAction(title: "Terrain", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .terrain
        }
        let hybridMapTypeAction = UIAlertAction(title: "Hybrid", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .hybrid
        }
        let cancelAction = UIAlertAction(title: "Close", style: UIAlertAction.Style.cancel) { (alertAction) -> Void in
        }
        
        actionSheet.addAction(normalMapTypeAction)
        actionSheet.addAction(terrainMapTypeAction)
        actionSheet.addAction(hybridMapTypeAction)
        actionSheet.addAction(cancelAction)
        
        present(actionSheet, animated: true, completion: nil)
    }
    
    
    func camUpdateWithNewPlace(_ newPlace: myPlace){
        let camera = GMSCameraPosition.camera(withLatitude: newPlace.coordinate.latitude,
                    longitude: newPlace.coordinate.longitude, zoom: zoomLevel)
        mapView.camera = camera
    }
    
    @IBAction func originTextFieldTaped(_ sender: Any) {
        originTextField.resignFirstResponder()
        let acController = GMSAutocompleteViewController()
        acController.delegate = self
        firstOne = true
        present(acController, animated: true, completion: nil)
    }
    
    @IBAction func destinationTextFieldTaped(_ sender: Any) {
        destinationTextField.resignFirstResponder()
        let acController = GMSAutocompleteViewController()
        acController.delegate = self
        firstOne = false
        present(acController, animated: true, completion: nil)
    }
    @IBAction func routeBuildPressed(_ sender: UIButton) {
        if self.routePolyline != nil {
            self.routePolyline!.map = nil
            self.routePolyline = nil
        }
        let orig = GoogleMapsDirections.Place.coordinate(coordinate: GoogleMapsService.LocationCoordinate2D(latitude: self.origin.coordinate.latitude, longitude: self.origin.coordinate.longitude))
        let dest = GoogleMapsDirections.Place.coordinate(coordinate: GoogleMapsService.LocationCoordinate2D(latitude: self.destination.coordinate.latitude, longitude: self.destination.coordinate.longitude))
        GoogleMapsDirections.direction(fromOrigin: orig, toDestination: dest)
        { (response, error) -> Void in
            // Check Status Code
            guard response?.status == GoogleMapsDirections.StatusCode.ok else {
                // Status Code is Not OK
                debugPrint(response?.errorMessage ?? "")
                let alert = UIAlertController(title: "Invalid request", message: "No existing routes", preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
                self.present(alert, animated: true)
                return
            }
            if let points = response?.routes.first?.overviewPolylinePoints {
                DispatchQueue.main.async {
                    let path = GMSPath(fromEncodedPath: points)
                    self.routePolyline = GMSPolyline(path: path)
                    self.routePolyline!.strokeWidth = 5.0
                    self.routePolyline!.strokeColor = #colorLiteral(red: 0.4666666687, green: 0.7647058964, blue: 0.2666666806, alpha: 1)
                    self.routePolyline!.map = self.mapView
                }
                self.duration = response?.routes.first?.legs.last?.duration?.text
                self.distance = response?.routes.first?.legs.last?.distance?.text
            }
            // Use .result or .geocodedWaypoints to access response details
            // response will have same structure as what Google Maps Directions API returns
            debugPrint("it has \(response?.routes.count ?? 0) routes")
        }
        let bounds = GMSCoordinateBounds(coordinate: origin.coordinate, coordinate: destination.coordinate)
        let camera = mapView.camera(for: bounds, insets: UIEdgeInsets(top: 100.0, left: 100.0, bottom: 100.0, right: 100.0))!
        mapView.camera = camera
    }
    
    @IBAction func swapPosition(_ sender: UIButton) {
        let swapPosition = origin
        origin = destination
        destination = swapPosition
        let swapText = originTextField.text
        originTextField.text = destinationTextField.text
        destinationTextField.text = swapText
    }
    
    @IBAction func currentPosition(_ sender: UIButton) {
        if CLLocationManager.authorizationStatus() != .authorizedWhenInUse {
            print("DORIME")
            let alert = UIAlertController(title: "Error", message: "Application has no permision for location. Do you want to turn it in?", preferredStyle: UIAlertController.Style.alert)
            
            alert.addAction(UIAlertAction(title: "OK", style: UIAlertAction.Style.default, handler: { (alert) in
                if let url = URL(string: "App-Prefs:root=Privacy&path=LOCATION") {
                    UIApplication.shared.open(url, options: [:], completionHandler: nil)
                }
            }))
            
            alert.addAction(UIAlertAction(title: "Cancel", style: UIAlertAction.Style.default, handler: nil))
            
            self.present(alert, animated: true)
            return
        }
        if (originMarker != nil) {
            originMarker!.map = nil
            originMarker = nil
        }
        origin.textField = "My location"
        origin.coordinate = mapView.myLocation!.coordinate
        origin.description = mapView.myLocation!.description
        originMarker = GMSMarker(position: origin.coordinate)
        originMarker!.title = "My location"
        originMarker!.map = self.mapView
        camUpdateWithNewPlace(origin)
        originTextField.text = origin.textField
    }
}
    
extension ViewController {
    
    func changeMapType() {
        let actionSheet = UIAlertController(title: "Map Types", message: "Select map type:", preferredStyle: UIAlertController.Style.actionSheet)
        let normalMapTypeAction = UIAlertAction(title: "Normal", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .normal
        }
        let terrainMapTypeAction = UIAlertAction(title: "Terrain", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .terrain
        }
        let hybridMapTypeAction = UIAlertAction(title: "Hybrid", style: UIAlertAction.Style.default) { (alertAction) -> Void in
            self.mapView.mapType = .hybrid
        }
        let cancelAction = UIAlertAction(title: "Close", style: UIAlertAction.Style.cancel) { (alertAction) -> Void in
        }
        actionSheet.addAction(normalMapTypeAction)
        actionSheet.addAction(terrainMapTypeAction)
        actionSheet.addAction(hybridMapTypeAction)
        actionSheet.addAction(cancelAction)
        
        present(actionSheet, animated: true, completion: nil)
    }
}

extension ViewController {
    func mapView(_ mapView: GMSMapView, idleAt position: GMSCameraPosition) {
        mapView.isMyLocationEnabled = true
    }
    
    func mapView(_ mapView: GMSMapView, didTapInfoWindowOf marker: GMSMarker) {
        mapView.isMyLocationEnabled = true
    }
    
    func mapView(_ mapView: GMSMapView, willMove gesture: Bool) {
        mapView.isMyLocationEnabled = true
        if (gesture) {
            mapView.selectedMarker = nil
        }
    }
    
    func mapView(_ mapView: GMSMapView, didTap marker: GMSMarker) -> Bool {
        mapView.isMyLocationEnabled = true
        return false
    }
    
    func mapView(_ mapView: GMSMapView, didTapAt coordinate: CLLocationCoordinate2D) {
        print("COORDINATE \(coordinate)") // when you tapped coordinate
    }
    
    func didTapMyLocationButton(for mapView: GMSMapView) -> Bool {
        mapView.isMyLocationEnabled = true
        mapView.selectedMarker = nil
        return false
    }
}

extension ViewController: GMSAutocompleteViewControllerDelegate  {
    
    func viewController(_ viewController: GMSAutocompleteViewController, didAutocompleteWith place: GMSPlace) {
        // Get the place name from 'GMSAutocompleteViewController'
        // Then display the name in textField
        
        if firstOne {
            if (self.originMarker != nil) {
                self.originMarker!.map = nil
                self.originMarker = nil
            }
            originTextField.text = place.name
            origin.textField = place.name ?? ""
            origin.coordinate = place.coordinate
            origin.description = place.formattedAddress!
            originMarker = GMSMarker(position: origin.coordinate)
            originMarker!.title = place.name
            originMarker!.map = self.mapView
            camUpdateWithNewPlace(origin)
        } else {
            if (self.destinationMarker != nil) {
                self.destinationMarker!.map = nil
                self.destinationMarker = nil
            }
            destinationTextField.text = place.name
            destination.textField = place.name ?? ""
            destination.coordinate = place.coordinate
            destination.description = place.formattedAddress!
            destinationMarker = GMSMarker(position: destination.coordinate)
            destinationMarker!.title = place.name
            destinationMarker!.map = self.mapView
            camUpdateWithNewPlace(destination)
        }
        dismiss(animated: true, completion: nil)
    }
    func viewController(_ viewController: GMSAutocompleteViewController, didFailAutocompleteWithError error: Error) {
        let alert = UIAlertController(title: "Error", message: "No such places found", preferredStyle: UIAlertController.Style.alert)
        let cancelAction = UIAlertAction(title: "Close", style: UIAlertAction.Style.cancel) { (alertAction) -> Void in
        }
        alert.addAction(cancelAction)
        present(alert, animated: true, completion: nil)
        print("Error: ", error.localizedDescription)
    }
    func wasCancelled(_ viewController: GMSAutocompleteViewController) {
        // Dismiss when the user canceled the action
        dismiss(animated: true, completion: nil)
    }
    
    func didRequestAutocompletePredictions(_ viewController: GMSAutocompleteViewController) {
        UIApplication.shared.isNetworkActivityIndicatorVisible = true
    }
    
    func didUpdateAutocompletePredictions(_ viewController: GMSAutocompleteViewController) {
        UIApplication.shared.isNetworkActivityIndicatorVisible = false
    }
}

extension ViewController: CLLocationManagerDelegate {
    // Handle incoming location events.
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        // Handle authorization for the location manager.
        if self.destination.textField != "" && self.origin.textField == "My location" {
            if self.routePolyline != nil {
                self.routePolyline!.map = nil
                self.routePolyline = nil
            }
            origin.coordinate = locations[0].coordinate
            let origin = GoogleMapsDirections.Place.coordinate(coordinate: GoogleMapsService.LocationCoordinate2D(latitude: self.origin.coordinate.latitude, longitude: self.origin.coordinate.longitude))
            let dest = GoogleMapsDirections.Place.coordinate(coordinate: GoogleMapsService.LocationCoordinate2D(latitude: self.destination.coordinate.latitude, longitude: self.destination.coordinate.longitude))
            GoogleMapsDirections.direction(fromOrigin: origin, toDestination: dest)
            { (response, error) -> Void in
                // Check Status Code
                guard response?.status == GoogleMapsDirections.StatusCode.ok else {
                    // Status Code is Not OK
                    debugPrint(response?.errorMessage ?? "")
                    let alert = UIAlertController(title: "Invalid request", message: "No existing routes", preferredStyle: .alert)
                    alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
                    self.present(alert, animated: true)
                    return
                }
                if let points = response?.routes.first?.overviewPolylinePoints {
                    DispatchQueue.main.async {
                        let path = GMSPath(fromEncodedPath: points)
                        self.routePolyline = GMSPolyline(path: path)
                        self.routePolyline!.strokeWidth = 5.0
                        self.routePolyline!.strokeColor = #colorLiteral(red: 0.4666666687, green: 0.7647058964, blue: 0.2666666806, alpha: 1)
                        self.routePolyline!.map = self.mapView
                    }
                }
                // Use .result or .geocodedWaypoints to access response details
                // response will have same structure as what Google Maps Directions API returns
            }
        }
    }
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .restricted:
            print("Location access was restricted.")
        case .denied:
            print("User denied access to location.")
            // Display the map using the default location.
            mapView.isHidden = false
        case .notDetermined:
            print("Location status not determined.")
        case .authorizedAlways: fallthrough
        case .authorizedWhenInUse:
            print("Location status is OK.")
        @unknown default:
            fatalError()
        }
    }
    // Handle location manager errors.
    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        self.locationManager.stopUpdatingLocation()
        print("Error: \(error)")
    }
}
