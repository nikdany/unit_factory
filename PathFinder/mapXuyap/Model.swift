//
//  Model.swift
//  mapXuyap
//
//  Created by Mykyta DANYLCHENKO on 10/13/19.
//  Copyright © 2019 Mykyta DANYLCHENKO. All rights reserved.
//

import Foundation
import MapKit
import GoogleMaps

var firstOne = true

struct myPlace {
    var description: String
    var textField: String
    var coordinate: CLLocationCoordinate2D
    var address: String
    
    init() {
        description = ""
        textField = ""
        coordinate = CLLocationCoordinate2D(latitude: 0.0, longitude: 0.0)
        address = ""
    }
}


