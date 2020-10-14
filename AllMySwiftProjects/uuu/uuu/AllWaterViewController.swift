//
//  AllWaterViewController.swift
//  uuu
//
//  Created by Григорий on 10.10.2020.
//

import UIKit
import MBCircularProgressBar


class AllWaterViewController: UIViewController {

    @IBOutlet weak var textField: UITextField!
    
    let progress = ViewController()
    
    override func viewDidLoad() {
        super.viewDidLoad()

    
        
    }
    
   
    
    
    @IBAction func saveAction(_ sender: UIButton) {
        UserDefaults.standard.set(Int(textField.text ?? ""), forKey: "water")
        UserDefaults.standard.set(Int(0), forKey: "1val")
        //progress.progressView.value = 0
    }
    
    
}
