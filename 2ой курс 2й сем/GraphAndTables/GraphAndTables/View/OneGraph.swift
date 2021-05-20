//
//  OneGraph.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import SwiftUI

struct OneGraph: View {
    
    let data: NodeModel
    
    var body: some View {
        ZStack {
            Circle()
                .stroke(lineWidth: 6)
            
            Circle()
                .foregroundColor(Color.blue)
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

struct OneGraph_Previews: PreviewProvider {
    static var previews: some View {
        OneGraph(data: NodeModel(name: "Выйти гулять", timeMax: 120, timeMin: 20))
    }
}
