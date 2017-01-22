//
//  ViewController.swift
//  VioozerSwiftDemoApp
//
//  Created by Yedidya Reiss on 17/01/2017.
//  Copyright © 2017 Yedidya Reiss. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    @IBOutlet weak var lblSDKState : UILabel!
    @IBOutlet weak var viewBaseLine : UIView!

    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        NotificationCenter.default.addObserver(self, selector: #selector(ViewController.vioozerIsReady), name: NSNotification.Name(rawValue: VIOOZER_IS_READY_NOTIFICATION), object: nil)
        
        NotificationCenter.default.addObserver(self, selector: #selector(ViewController.vioozerFailed), name: NSNotification.Name(rawValue: VIOOZER_FAILED_NOTIFICATION), object: nil)
        
        
    }
    
    
    deinit {
        NotificationCenter.default.removeObserver(self)
    }

    func vioozerIsReady() {
        OperationQueue.main.addOperation {
            self.lblSDKState.text = "INITIALIZATION OK"
            self.lblSDKState.textColor = UIColor.green
            self.viewBaseLine.backgroundColor = UIColor.green
        }
    }
    
    func vioozerFailed() {
        OperationQueue.main.addOperation {
            self.lblSDKState.text = "INITIALIZATION ERROR"
            self.lblSDKState.textColor = UIColor.red
            self.viewBaseLine.backgroundColor = UIColor.red
        }
    }

    @IBAction func presentQuestion() {
        let c = CLLocationCoordinate2D(latitude: 37.759734, longitude: -122.427063)
        
        if let l = VioozerLocation(coordinaes: c , name: "Dolores Park", type: "Park", andAddress: "19th & Dolores St, San Francisco, CA 94114, USA") {
            
            VioozerAPI.sharedInstance().showAskQuestion(onLocations: [l], inCategories: [])
        }
    }
    
    
    @IBAction func presentVioozerActivity() {
        VioozerAPI.sharedInstance().openMyActivity()
    }
    

}

