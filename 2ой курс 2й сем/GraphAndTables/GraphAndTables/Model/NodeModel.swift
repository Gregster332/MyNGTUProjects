//
//  NodeModel.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import Foundation


struct NodeModel: Identifiable, Hashable {
    
    var id = UUID()
    var name: String
    var timeMin: Int
    var timeMax: Int
    
    
    init(name: String, timeMax: Int, timeMin: Int) {
        self.name = name
        self.timeMax = timeMax
        self.timeMin = timeMin
        
    }
    
}
