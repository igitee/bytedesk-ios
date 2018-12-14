//
//  KFDSMessageModel.h
//  bdcore
//
//  Created by 萝卜丝 on 2018/11/24.
//  Copyright © 2018年 Bytedesk.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface BDMessageModel : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

// 本地表主键id
@property(nonatomic, strong) NSNumber *local_id;
// 服务器端主键
@property(nonatomic, strong) NSNumber *server_id;
// 唯一数字id，保证唯一性
@property(nonatomic, strong) NSString *mid;
// 消息所属工作组wid
@property(nonatomic, strong) NSString *wid;
// 一对一会话接收方的uid
@property(nonatomic, strong) NSString *cid;
// 群组会话工作组的gid
@property(nonatomic, strong) NSString *gid;
// 消息类型
@property(nonatomic, strong) NSString *type;
// 会话类型：访客会话thread、联系人一对一会话contact，群组会话group
@property(nonatomic, strong) NSString *session_type;
// 来源客户端
@property(nonatomic, strong) NSString *client;
// 文本消息
@property(nonatomic, strong) NSString *content; // 文本消息
// 图片消息:
@property(nonatomic, strong) NSString *pic_url; // 微信pic_url，web版容易引起跨域访问问题，所以要使用image_url
//
@property(nonatomic, strong) NSString *image_url; // 存储在自己服务器之后的url
// 文件消息类型：文件url, 文件类型通过format标示
@property(nonatomic, strong) NSString *file_url;
// 语音消息
@property(nonatomic, strong) NSString *media_id; // 图片+语音+视频+短视频 公用字段
@property(nonatomic, strong) NSString *format; // 语音格式amr等
@property(nonatomic, strong) NSString *voice_url; // 语音url
@property(nonatomic, strong) NSNumber *length; // 时间长度
@property(nonatomic, strong) NSNumber *played; // 是否播放过
// 视频消息 & 短视频消息
@property(nonatomic, strong) NSString *thumb_media_id; // 视频消息 & 短视频消息
@property(nonatomic, strong) NSString *video_or_short_url; // 视频和短视频 url
@property(nonatomic, strong) NSString *video_or_short_thumb_url; // 视频和短视频 thumb url
// 地理位置消息
@property(nonatomic, strong) NSString *location_x;
@property(nonatomic, strong) NSString *location_y;
@property(nonatomic, strong) NSString *scale;
@property(nonatomic, strong) NSString *label;
// 链接消息
@property(nonatomic, strong) NSString *title;
@property(nonatomic, strong) NSString *mdescription;
@property(nonatomic, strong) NSString *url;
// 消息创建时间
@property(nonatomic, strong) NSString *created_at;
// 消息发送状态
@property(nonatomic, strong) NSString *status; // 命名为status会跟objective-c系统默认命名冲突
// 消息发送人
@property(nonatomic, strong) NSString *uid;
@property(nonatomic, strong) NSString *username;
@property(nonatomic, strong) NSString *nickname;
@property(nonatomic, strong) NSString *avatar;
// 消息所属会话tid
@property(nonatomic, strong) NSString *thread_tid;
// 消息对应会话的visitor uid
@property(nonatomic, strong) NSString *visitor_uid;
// 当前登录用户Uid
@property(nonatomic, strong) NSString *current_uid;
// 是否是访客
@property(nonatomic, strong) NSNumber *visitor;
//
@property(nonatomic, assign) CGSize     contentSize;
@property(nonatomic, assign) UIEdgeInsets  contentViewInsets;
//@property(nonatomic, assign) UIEdgeInsets  bubbleViewInsets;
//
- (BOOL)isSend;
- (BOOL)isNotification;

@end








