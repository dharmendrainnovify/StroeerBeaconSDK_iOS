//
//  SPXLocation.h
//
//  Copyright © 2015 match2blue. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

static CLLocationAccuracy const SPXUnknownLocationAccuracy = -1;

/**
 *  This class represents a outdoor location.
 */
@interface SPXLocation : NSObject <NSCopying, NSCoding>

/**
 *  The Latitude of the location.
 */
@property (nonatomic) CLLocationDegrees latitude;

/**
 *  The longitude of the location.
 */
@property (nonatomic) CLLocationDegrees longitude;

/**
 *  The current estimated accuracy of the position in metres.
 *  Can be used to draw an accuracy circle around the user position on the map.
 */
@property (nonatomic) CLLocationAccuracy accuracy;

/**
 *  The timestamp when the location was calculated.
 */
@property (nonatomic) NSDate *timestamp;

/**
 *  Method to create a new outdoor location.
 *
 *  @param coordinate   Coordinate of the location
 *
 *  @return A new @p SPXLocation object initialzed with the given values and a accuracy of @p SPXUnknownLocationAccuracy.
 */
+ (SPXLocation*)locationWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  Method to create a new outdoor location.
 *
 *  @param lat   Latitude of the location
 *  @param lng   Longitude of the location
 *
 *  @return A new @p SPXLocation object initialzed with the given values and a accuracy of @p SPXUnknownLocationAccuracy.
 */
+ (SPXLocation*)locationWithLatitude:(CLLocationDegrees)lat longitude:(CLLocationDegrees)lng;

/**
 *  Method to create a new outdoor location.
 *
 *  @param lat      Latitude of the location
 *  @param lng      Longitude of the location
 *  @param accuracy The estimated accuracy of the location.
 *
 *  @return A new @p SPXLocation object initialzed with the given values.
 */
+ (SPXLocation*)locationWithLatitude:(CLLocationDegrees)lat longitude:(CLLocationDegrees)lng accuracy:(CLLocationAccuracy)accuracy;

/**
 *  Helper method to get the CLLocationCoordinate2D representation of latitude and longitude of the location.
 *
 *  @return The coordinates of the location.
 */
- (CLLocationCoordinate2D)coordinate;

/**
 *  Calculates the distance between two locations.
 *
 *  @param location another location
 *
 *  @return Returns the distance between two locations.
 */
- (CLLocationDistance)distanceFromLocation:(SPXLocation*)location;

/**
 *  Calculates the distance between a SPXLocation and a CLLocation instance.
 *  The floor won't be taken into account.
 *
 *  @param location A CLLocation instance.
 *
 *  @return Returns the distance between two locations.
 */
- (CLLocationDistance)distanceFromCLLocation:(CLLocation*)location;

NS_ASSUME_NONNULL_END

@end
