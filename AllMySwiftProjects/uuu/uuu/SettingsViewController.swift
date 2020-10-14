//
//  SettingsViewController.swift
//  uuu
//
//  Created by Григорий on 11.10.2020.
//

import UIKit


class SettingsViewController: UIViewController {
    
    @IBOutlet weak var progressColors: UISegmentedControl!
    
    @IBOutlet weak var backgrounds: UISegmentedControl!
    
    let colorArray = [UIColor(named: "white"), UIColor(named: "blue"), UIColor(named: "pink")]
    //var index = UserDefaults.standard.value(forKey: "index")
    //let progressColorArray = [UIColor(named: "blueProgress"), UIColor(named: "green"), UIColor(named: "orange")]
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.backgrounds.addTarget(self, action: #selector(valueChange), for: .valueChanged)
        
        self.progressColors.addTarget(self, action: #selector(progressValueChanged), for: .valueChanged)
        
        backgrounds.selectedSegmentIndex = UserDefaults.standard.integer(forKey: "index")
        view.backgroundColor = self.colorArray[backgrounds.selectedSegmentIndex]
       
        progressColors.selectedSegmentIndex = UserDefaults.standard.integer(forKey: "progressIndex")
       
        
    }
    
    @objc func valueChange(target: UISegmentedControl){
        if target == self.backgrounds{
            let segmentIndex = target.selectedSegmentIndex
            view.backgroundColor = self.colorArray[segmentIndex]
           
            UserDefaults.standard.set(segmentIndex, forKey: "index")
            //backgrounds.selectedSegmentIndex = UserDefaults.standard.integer(forKey: "index")
            
        }
        
        //if backgrounds.value(forKey: "index") != nil {
        //   //
       // }
       
    }
    
    @objc func progressValueChanged(target: UISegmentedControl){
        if target  == self.progressColors{
            let segmentIndex = target.selectedSegmentIndex
            UserDefaults.standard.set(segmentIndex, forKey: "progressIndex")
            
        }
        
    }
  
    @IBAction func saveSettingsAction(_ sender: UIButton) {
        UserDefaults.standard.synchronize()
    }
    
}
