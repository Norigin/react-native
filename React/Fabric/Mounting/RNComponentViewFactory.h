/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <React/RNComponentViewProtocol.h>

#import <react/uimanager/ComponentDescriptorRegistry.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Registry of supported component view classes that can instantiate
 * view component instances by given component handle.
 */
@interface RNComponentViewFactory : NSObject

/**
 * Constructs and returns an instance of the class with a bunch of already registered standard components.
 */
+ (RNComponentViewFactory *)standardComponentViewFactory;

/**
 * Registers a component view class in the factory.
 */
- (void)registerComponentViewClass:(Class<RNComponentViewProtocol>)componentViewClass;

/**
 * Unregisters a component view class in the factory.
 */
- (void)unregisterComponentViewClass:(Class<RNComponentViewProtocol>)componentViewClass;

/**
 * Creates a component view with given component handle.
 */
- (UIView<RNComponentViewProtocol> *)createComponentViewWithComponentHandle:
    (facebook::react::ComponentHandle)componentHandle;

/**
 * Creates *managed* `ComponentDescriptorRegistry`. After creation, the object continues to store a weak pointer to the
 * registry and update it accordingly to the changes in the object.
 */
- (facebook::react::ComponentDescriptorRegistry::Shared)createComponentDescriptorRegistryWithParameters:
    (facebook::react::ComponentDescriptorParameters)parameters;

@end

NS_ASSUME_NONNULL_END