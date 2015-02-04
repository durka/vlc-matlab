//
//  MexWindowHelper.m
//  MexWindowHelper
//
//  Created by Alex Burka on 1/28/15.
//  Copyright (c) 2015 Alex Burka. All rights reserved.
//

#import "MexWindowHelper.h"

@implementation MexWindowHelper

NSView *create_window(NSWindow **pwin, float x, float y, float w, float h)
{
    [NSApplication sharedApplication];
    
    *pwin = [[NSWindow alloc] initWithContentRect:NSMakeRect(x, y, w, h)
                                       styleMask:NSTitledWindowMask
                                         backing:NSBackingStoreBuffered
                                           defer:YES];
    
    NSWindow *win = *pwin;
    
    [win setTitle:@"MEX window"];
    [win makeKeyAndOrderFront:nil];
    
    CGRect winRect = [[win contentView] bounds];
    NSView* maxView = [[NSView alloc] initWithFrame: winRect];
    [[win contentView] addSubview:maxView];
    
    return maxView;
}

@end