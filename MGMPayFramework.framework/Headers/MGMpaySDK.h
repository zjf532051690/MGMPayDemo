//
//  MGMpaySDK.h
//  MGMFramework
//
//  Created by MAC on 2020/2/26.
//  Copyright © 2020 MAC. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^CompletionBlock)(NSDictionary *resultDic);


@interface MGMpaySDK : NSObject

/**
 *  创建支付单例服务
 *
 *  @return 返回单例对象
 */
+ (MGMpaySDK *)defaultService;


/**
 *  支付接口
 *
 *  @param orderStr        支付订单信息字串
 *  @param schemeStr       调用支付的app注册在info.plist中的scheme
 *  @param completionBlock MGM结果回调Block
 */
- (void)payOrder:(NSString *)orderStr fromScheme:(NSString *)schemeStr callback:(CompletionBlock)completionBlock;;



/**
 *  处理MGM app支付后跳回商户app携带的支付结果Url
 *
 *  @param resultUrl        MGM app返回的支付结果url
 *  @param completionBlock  支付结果回调 为nil时默认使用支付接口的completionBlock
 */
- (void)processOrderWithPaymentResult:(NSURL *)resultUrl standbyCallback:(CompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
