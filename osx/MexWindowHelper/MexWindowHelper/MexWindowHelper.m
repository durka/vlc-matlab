//
//  MexWindowHelper.m
//  MexWindowHelper
//
//  Created by Alex Burka on 1/28/15.
//  Copyright (c) 2015 Alex Burka. All rights reserved.
//

#import "MexWindowHelper.h"

BOOL closing = NO;

@implementation MexWindowHelper

NSView *create_window(NSWindow **pwin, float x, float y, float w, float h, char *title)
{
    [NSApplication sharedApplication];
    
    *pwin = [[MexWindow alloc] initWithContentRect:NSMakeRect(x, y, w, h)
                                         styleMask:NSTitledWindowMask
                                           backing:NSBackingStoreBuffered
                                             defer:YES];
    
    NSWindow *win = *pwin;
    
    NSString *nstitle = title
        ? [NSString stringWithCString:title encoding:NSUTF8StringEncoding]
        : @"VLC-Matlab";
    [win setTitle:nstitle];
    [win makeKeyAndOrderFront:nil];
    
    CGRect winRect = [[win contentView] bounds];
    NSView* maxView = [[NSView alloc] initWithFrame: winRect];
    [[win contentView] addSubview:maxView];
    
    return maxView;
}

void close_window(NSWindow *win)
{
    if (win)
    {
        closing = YES;
        [win close];
        closing = NO;
    }
}

@end

@implementation MexWindow

- (BOOL)windowShouldClose:(id)sender
{
    return closing;
}

@end

