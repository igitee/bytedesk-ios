//
//  KFDSInputEmotionManager.h
//  feedback
//
//  Created by 萝卜丝·Bytedesk.com on 2017/2/24.
//  Copyright © 2017年 萝卜丝·Bytedesk.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KFDSInputEmotion : NSObject

//@property (nonatomic,strong)    NSString    *EmotionID;
@property (nonatomic,strong)    NSString    *text;
@property (nonatomic,strong)    NSString    *filename;

@end


@interface KFDSInputEmotionLayout : NSObject

@property (nonatomic, assign) NSInteger rows;               //行数
@property (nonatomic, assign) NSInteger columes;            //列数
@property (nonatomic, assign) NSInteger itemCountInPage;    //每页显示几项
@property (nonatomic, assign) CGFloat   cellWidth;          //单个单元格宽
@property (nonatomic, assign) CGFloat   cellHeight;         //单个单元格高
@property (nonatomic, assign) CGFloat   imageWidth;         //显示图片的宽
@property (nonatomic, assign) CGFloat   imageHeight;        //显示图片的高
@property (nonatomic, assign) BOOL      emoji;

- (id)initEmojiLayout:(CGFloat)width;

- (id)initCharletLayout:(CGFloat)width;

@end

@interface KFDSInputEmotionCatalog : NSObject

@property (nonatomic,strong)    KFDSInputEmotionLayout *layout;
@property (nonatomic,strong)    NSString        *catalogID;
@property (nonatomic,strong)    NSString        *title;
@property (nonatomic,strong)    NSDictionary    *id2Emotions;
@property (nonatomic,strong)    NSDictionary    *tag2Emotions;
@property (nonatomic,strong)    NSArray         *Emotions;
@property (nonatomic,strong)    NSString        *icon;             //图标
@property (nonatomic,strong)    NSString        *iconPressed;      //小图标按下效果
@property (nonatomic,assign)    NSInteger       pagesCount;        //分页数
@end

@interface KFDSInputEmotionManager : NSObject

+ (instancetype)sharedManager;

- (KFDSInputEmotion *)emotionByText:(NSString *)text;

@end





