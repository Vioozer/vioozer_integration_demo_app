//
//  ViewController.m
//  VioozerIntergrationDemoApp
//
//  Created by Yedidya Reiss on 17/01/2017.
//  Copyright © 2017 Yedidya Reiss. All rights reserved.
//

#import "ViewController.h"
#import <VioozerAPI.h>
@interface ViewController ()

@property (weak,nonatomic) IBOutlet UILabel* lblSDKState;
@property (weak,nonatomic) IBOutlet UIView* viewBaseLine;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(vioozerReady)
                                                 name:VIOOZER_IS_READY_NOTIFICATION object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(vioozerFailed)
                                                 name:VIOOZER_FAILED_NOTIFICATION object:nil];
    
}


-(void) vioozerReady {
    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
        _lblSDKState.text = @"INITIALIZATION OK";
        _lblSDKState.textColor = [UIColor greenColor];
        _viewBaseLine.backgroundColor = [UIColor greenColor];
    }];
    
}

-(void) vioozerFailed {
    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
        _lblSDKState.text = @"INITIALIZATION ERROR";
        _lblSDKState.textColor = [UIColor redColor];
        _viewBaseLine.backgroundColor = [UIColor redColor];
    }];
}


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (IBAction) presentQuestion {
    
    // name, type and address are free-text fields.
    VioozerLocation * l = [VioozerLocation VioozerLocationWithCoordinaes:CLLocationCoordinate2DMake (37.759734, -122.427063)
                                                                    name:@"Dolores Park"
                                                                    type:@"Park"
                                                              andAddress:@"19th & Dolores St, San Francisco, CA 94114, USA"];
    
    
    [VIOOZER_API showAskQuestionOnLocations:@[l] inCategories:@[]];
}


-(IBAction)presentVioozerMyAvtivity {
    [VIOOZER_API openMyActivity];
}

@end
