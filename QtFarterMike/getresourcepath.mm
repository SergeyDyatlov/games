#include "getresourcepath.h"
#import <Foundation/Foundation.h>

std::string getResourcePath()
{
  return [[[NSBundle mainBundle] resourcePath] UTF8String];
}