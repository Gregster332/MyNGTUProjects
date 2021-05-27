//
//  TableView.swift
//  GraphAndTables
//
//  Created by Григорий on 18.05.2021.
//

import SwiftUI

struct TableView: View {
    var body: some View {
        ScrollView {
        VStack(spacing: 0) {
            ForEach(data.indices) { item in
                
                ZStack{
                    
                    RoundedRectangle(cornerRadius: 10)
                        .fill(Color(#colorLiteral(red: 0.8078431487, green: 0.02745098062, blue: 0.3333333433, alpha: 1)))
                    
                    List(data[item]) { index in
                        VStack(alignment: .leading){
                            Text(index.name)
                            
                            
                            Text("Мин время: \(index.timeMin) мин.")
                            Text("Макс время: \(index.timeMax) мин.")
                            
                        }
                        .padding()
                    }
                    .frame(width: .infinity, height: 200, alignment: .center)
                    .padding()
                }.padding()
                
                if item != data.indices.last {
                    Image(systemName: "chevron.down")
                        .font(.system(size: 30))
                }
                
                }
            }
        }
    }
}

struct TableView_Previews: PreviewProvider {
    static var previews: some View {
        TableView()
    }
}
