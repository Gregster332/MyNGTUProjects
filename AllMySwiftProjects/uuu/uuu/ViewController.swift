//
//  ViewController.swift
//  uuu
//
//  Created by Григорий on 07.10.2020.
//

import UIKit
import QuartzCore
import MBCircularProgressBar



class ViewController: UIViewController {
   
    @IBOutlet weak var firstButton: UIButton!
    @IBOutlet weak var secondButton: UIButton!
    @IBOutlet weak var thirdButton: UIButton!
    @IBOutlet weak var otherButton: UIButton!
    @IBOutlet weak var buttonsView: UIView!
    @IBOutlet weak var progressView: MBCircularProgressBarView!
    @IBOutlet weak var plusStackView: UIStackView!
    
    @IBOutlet weak var btnView: UIView!
    
    @IBOutlet weak var addText: UILabel!
    @IBOutlet weak var addSlider: UISlider!
    
    
    @IBOutlet weak var gidroText: UILabel!
    @IBOutlet weak var settBtn: UIButton!
    @IBOutlet weak var profBtn: UIButton!
    
    let colorArray = [UIColor(named: "white"), UIColor(named: "blue"), UIColor(named: "pink")]
    let progressColorArray = [UIColor(named: "blueProgress"), UIColor(named: "green"), UIColor(named: "orange")]
    
    
    
    var numberForTarget = false
    
    override func viewDidLoad() {
        super.viewDidLoad()
       
        customButton(firstButton)
        customButton(secondButton)
        customButton(thirdButton)
        customButton(otherButton)
        
        
        self.addSlider.minimumValue = 0
        self.addSlider.maximumValue = 3000
        
        UserDefaults.standard.synchronize()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let index = UserDefaults.standard.integer(forKey: "index")
        let progressIndex = UserDefaults.standard.integer(forKey: "progressIndex")
        
        var counterOfPercents = UserDefaults.standard.integer(forKey: "1val")
        progressView.value = CGFloat(counterOfPercents)
        
        if index == 0{
            UserDefaults.standard.synchronize()
            view.backgroundColor = colorArray[0]
            plusStackView.backgroundColor = colorArray[0]
            btnView.backgroundColor = colorArray[0]
            gidroText.backgroundColor = colorArray[0]
            settBtn.backgroundColor = colorArray[0]
            progressView.backgroundColor = colorArray[0]
        } else if index == 1{
            UserDefaults.standard.synchronize()
            view.backgroundColor = colorArray[1]
            plusStackView.backgroundColor = colorArray[1]
            btnView.backgroundColor = colorArray[1]
            gidroText.backgroundColor = colorArray[1]
            settBtn.backgroundColor = colorArray[1]
            progressView.backgroundColor = colorArray[1]
        } else{
            UserDefaults.standard.synchronize()
            view.backgroundColor = colorArray[2]
            plusStackView.backgroundColor = colorArray[2]
            btnView.backgroundColor = colorArray[2]
            gidroText.backgroundColor = colorArray[2]
            settBtn.backgroundColor = colorArray[2]
            progressView.backgroundColor = colorArray[2]
        }
        
        
        if progressIndex == 0{
            progressView.progressColor = progressColorArray[0]
            progressView.fontColor = progressColorArray[0]
        } else if progressIndex == 1{
            progressView.progressColor = progressColorArray[1]
            progressView.fontColor = progressColorArray[1]
        }else if progressIndex == 2{
            progressView.progressColor = progressColorArray[2]
            progressView.fontColor = progressColorArray[2]
        }
        
        
    }
    
    func customButton(_ button: UIButton){
        button.layer.cornerRadius = 14
        button.layer.borderWidth = 1
        button.layer.borderColor = #colorLiteral(red: 0.06274510175, green: 0, blue: 0.1921568662, alpha: 1)
        button.layer.shadowColor = CGColor(red: 255, green: 255, blue: 255, alpha: 1.0)
        button.layer.shadowRadius = 5
        button.layer.shadowOpacity = 0.2
        
    }
    
    func animate(_ button: UIButton, _ value: Int){
        UIView.animate(withDuration: 1, delay: 0, options: .curveEaseInOut, animations: {
            self.progressView.value += CGFloat(value)
            UserDefaults.standard.set(self.progressView.value, forKey: "1val")
            
           
        }, completion: nil)
    }
    
   
    
    @IBAction func firstAction(_ sender: UIButton) {
        animate(firstButton, 100*150/(UserDefaults.standard.value(forKey: "water") as! Int))
    }
    
    @IBAction func secondAction(_ sender: UIButton) {
        animate(secondButton, 100*250/(UserDefaults.standard.value(forKey: "water") as! Int))
    }
    
    
    @IBAction func thirdAction(_ sender: UIButton) {
        animate(thirdButton, 100*500/(UserDefaults.standard.value(forKey: "water") as! Int))
    }
    
    @IBAction func otherAction(_ sender: UIButton) {
        UIView.animate(withDuration: 1, delay: 0, usingSpringWithDamping: 5, initialSpringVelocity: 5, options: .curveEaseInOut, animations: {
            self.numberForTarget.toggle()
            self.progressView.center.y -= self.numberForTarget ? 200 : -200
            self.buttonsView.center.y -= self.numberForTarget ? 200 : -200
            self.plusStackView.center.y -= self.numberForTarget ? 200 : -200
            self.gidroText.center.y -= self.numberForTarget ? 200 : -200
            self.settBtn.center.y -= self.numberForTarget ? 200 : -200
            self.profBtn.center.y -= self.numberForTarget ? 200 : -200
            
            
        })
    }
    
    
    @IBAction func clearAction(_ sender: UIBarButtonItem) {
        self.progressView.value = 0
        UserDefaults.standard.set(progressView.value, forKey: "1val")
    }
    ////????
    @IBAction func sliderValue(_ sender: UISlider) {
        let currentValue = Int(sender.value)
        
        self.addText.text = "\(currentValue)"
    }
    
}

