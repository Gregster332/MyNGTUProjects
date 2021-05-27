//
//  OneGraph.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import SwiftUI

struct OneGraph: View {
    
    let data: NodeModel
    @Binding var changeFigure: Bool
    
    func createFigure() -> String {
        let newFigure = FactoryOfFigures.shared.createFigure(name: changeFigure ? .blueRectangle : .pinkCircle)
        return newFigure.changeTypeOfFigure()
    }
    
    func getColor() -> Color{
        let newColor = FactoryOfFigures.shared.createFigure(name: changeFigure ? .blueRectangle : .pinkCircle)
        return newColor.chageColor()
    }
    
    var body: some View {
        
        if createFigure() == "Circle" {
            
            ZStack {
                
                
                
                Circle()
                    .stroke(lineWidth: 6)
                
                Circle()
                    .foregroundColor(getColor())
                    .frame(width: 194, height: 194)
                
                VStack(alignment: .center, spacing: -40) {
                    Text(data.name)
                        .font(.system(size: 18))
                        .fontWeight(.bold)
                        .font(.title)
                        .lineLimit(nil)
                        .multilineTextAlignment(.center)
                        .frame(width: 170, height: 170)
                    
                    Text("Мин время: \(data.timeMin) мин")
                    Text("Макс время: \(data.timeMax) мин")
                    
                    Spacer()
                }
                
                
            }.frame(width: 170, height: 170)
        } else {
            ZStack {
                
                Rectangle()
                    .stroke(lineWidth: 6)
                
                Rectangle()
                    .foregroundColor(getColor())
                    .frame(width: 194, height: 194)
                
                VStack(alignment: .center, spacing: -40) {
                    Text(data.name)
                        .font(.system(size: 18))
                        .fontWeight(.bold)
                        .font(.title)
                        .lineLimit(nil)
                        .multilineTextAlignment(.center)
                        .frame(width: 170, height: 170)
                    
                    Text("Мин время: \(data.timeMin) мин")
                    Text("Макс время: \(data.timeMax) мин")
                    
                    Spacer()
                }
                
                
            }.frame(width: 170, height: 170)
        }
    }
}

struct OneGraph_Previews: PreviewProvider {
    static var previews: some View {
        OneGraph(data: NodeModel(name: "Выйти гулять", timeMax: 120, timeMin: 20), changeFigure: .constant(false))
    }
}
