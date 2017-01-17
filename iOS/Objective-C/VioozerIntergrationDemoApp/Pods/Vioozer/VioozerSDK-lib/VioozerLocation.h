//
//  VioozerLocation.h
//  VioozerAPI
//
//  Created by Zeev on 4/30/14.
//  Copyright (c) 2014 Quickode. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreLocation;

/**
 *  object for location details
 */
@interface VioozerLocation : NSObject

/**for Internal use*/
@property (strong,nonatomic) NSString *iconUrl;
/** location name */
@property (strong, nonatomic) NSString* locationName;
/** location cordinades */
@property (assign, nonatomic) CLLocationCoordinate2D coordinates;
/** locationn address */
@property (strong, nonatomic) NSString* address;
/** location type (e.g. “Estadio”) */
@property (strong, nonatomic) NSString* locationType;
/** location number */
@property (assign, nonatomic) NSInteger locationNumber;
/** location id */
@property (strong, nonatomic) NSString* locationId;
/** place id */
@property (strong, nonatomic) NSString* placeId;
/** is location checked*/
@property (assign, nonatomic) BOOL isLocationChecked;
/*non standart parameters*/
@property (strong, nonatomic) NSDictionary* extraParameters;

/**
 *  convenience constructors with coordinates only (required parameter)
 *
 *  @param coordinates location coordinates
 *
 *  @return new 'VioozerLocation' with received coordinates
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates;

/**
 *  convenience constructors
 *
 *  @param coordinates  location coordinates
 *  @param locationName location name - like "Estadio Olímpico Universitario"
 *  @param locationType string of location type
 *  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
 *
 *  @return new 'VioozerLocation' with received parameters
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
                                             name:(NSString*)locationName
                                             type:(NSString*)locationType
                                       andAddress:(NSString*)address;


+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
                                             name:(NSString*)locationName
                                             type:(NSString*)locationType
                                          placeId:(NSString*)placeId
                                       andAddress:(NSString*)address;

/**
 *  convenience constructors all fields
 *
 *  @param coordinates  location coordinates
 *  @param locationName location name - like "Estadio Olímpico Universitario"
 *  @param locationType string of location type
 *  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
 *  @param locationNumber - location number
 *  @return new 'VioozerLocation' with received parameters
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
											 name:(NSString*)locationName
											 type:(NSString*)locationType
									   andAddress:(NSString*)address
                                andLocationNumber:(NSInteger) locationNumber;

/**
*  convenience constructors all fields
*
*  @param coordinates  location coordinates
*  @param locationName location name - like "Estadio Olímpico Universitario"
*  @param locationType string of location type
*  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
*  @param locationNumber - location number
*  @param listingId - the given ID
*  @return new 'VioozerLocation' with received parameters
*/
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
											 name:(NSString*)locationName
											 type:(NSString*)locationType
									   andAddress:(NSString*)address
                                andLocationNumber:(NSInteger) locationNumber
                                      withPlaceId:(NSString *)placeId;

/**
 *  convenience constructors all fields
 *
 *  @param coordinates  location coordinates
 *  @param locationName location name - like "Estadio Olímpico Universitario"
 *  @param locationType string of location type
 *  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
 *  @param placeId - the given ID
 *  @return new 'VioozerLocation' with received parameters
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
											 name:(NSString*)locationName
											 type:(NSString*)locationType
									   andAddress:(NSString*)address withPlaceId:(NSString *)placeId;

/**
 *  convenience constructors all fields
 *
 *  @param coordinates  location coordinates
 *  @param locationName location name - like "Estadio Olímpico Universitario"
 *  @param locationType string of location type
 *  @param locationNumber - location number
 *  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
 *  @param placeId - the given ID
 *  @param extraParameters - non standart parameters
 *  @return new 'VioozerLocation' with received parameters
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
                                             name:(NSString*)locationName
                                          address:(NSString*)address
                                     locationType:(NSString*)locationType
                                   locationNumber:(NSInteger)locationNumber
                                       locationId:(NSString*)locationId
                                          placeId:(NSString*)placeId
                                  extraParameters:(NSDictionary*)extraParameters;



/**
 *  convenience constructors all fields
 *
 *  @param coordinates  location coordinates
 *  @param locationName location name - like "Estadio Olímpico Universitario"
 *  @param address      location address - like "AV. Insurgentes Sur S/N, Col."
 *  @param extraParameters - non standart parameters
 *  @return new 'VioozerLocation' with received parameters
 */
+(VioozerLocation*) VioozerLocationWithCoordinaes:(CLLocationCoordinate2D)coordinates
                                             name:(NSString*)locationName
                                          address:(NSString*)address
                                  extraParameters:(NSDictionary*)extraParameters;


/**
 *Sets the isLocationChecked parameter
 */
-(void)setIsLocationChecked:(BOOL)isLocationChecked;


@end
