//
//  ContentView.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import SwiftUI

struct ContentView: View {
    
    @State private var selectedIndex: Int = 1
    
    var body: some View {
        VStack {
            
            Picker(selection: $selectedIndex, label: Text("Picker"), content: {
                Text("Таблица").tag(1)
                Text("Граф").tag(2)
            })
            .pickerStyle(SegmentedPickerStyle())
            .padding()
            
            Spacer()
            
            if selectedIndex == 1 {
                TableView()
                    
            } else {
                Graph()
            }
            
            Spacer()
            
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
