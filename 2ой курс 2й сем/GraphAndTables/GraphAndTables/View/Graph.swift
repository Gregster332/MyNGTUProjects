//
//  Graph.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import SwiftUI

struct Graph: View {
    
    let colors = [Color.red, .blue, .purple, .green, .yellow]
    @State private var changeFigure: Bool = false
    
    var body: some View {
        
        VStack {
            
            Picker(selection: $changeFigure, label: Text("Picker"), content: {
                Text("Розовые кружки").tag(false)
                Text("Голубые квадраты").tag(true)
            })
            .pickerStyle(SegmentedPickerStyle())
            .padding()
        
        ScrollView(.horizontal) {
            HStack (spacing: 20) {
                ForEach(data.indices) { index in
                    
                    
                    ZStack {
                        Rectangle()
                            .frame(width: 5, height:  CGFloat(data[index].count) * 200)
                        
                        
                        VStack (spacing: 50) {
                            ForEach(data[index]) {
                                graph in
                                OneGraph(data: graph, changeFigure: $changeFigure)
                                
                                
                            }
                        }
                        
                        
                    }
                    if index != data.indices.last {
                        Image(systemName: "chevron.right")
                            .font(.system(size: 30))
                    }
                    
                }
                
            }
        }
        .padding()
        }
    }
}




struct Graph_Previews: PreviewProvider {
    static var previews: some View {
        Graph()
    }
}
