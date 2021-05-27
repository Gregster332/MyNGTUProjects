//
//  FactoryOfFigures.swift
//  GraphAndTables
//
//  Created by Григорий on 27.05.2021.
//

import Foundation


enum Figures {
    case blueRectangle, pinkCircle
}

class FactoryOfFigures {
    
    static let shared = FactoryOfFigures()
    
    func createFigure(name: Figures) -> Figure{
        
        switch name {
        case .blueRectangle: return BlueRectangle()
        case .pinkCircle: return PinkCircle()
        }
        
    }
    
}
