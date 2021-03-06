//
//  KFVisitorApiViewController.m
//  demo
//
//  Created by 萝卜丝 on 2018/11/22.
//  Copyright © 2018年 Bytedesk.com. All rights reserved.
//

#import "KFVisitorApiViewController.h"
#import <SafariServices/SafariServices.h>

#import "KFVisitorLoginViewController.h"
#import "KFVisitorChatViewController.h"
#import "KFVisitorProfileViewController.h"
#import "KFVisitorStatusViewController.h"
#import "KFVisitorThreadViewController.h"
//#import "KFVisitorFeedbackViewController.h"
//#import "KFVisitorFAQViewController.h"
//#import "KFVisitorLeavemsgViewController.h"
#import <bytedesk-core/bdcore.h>

//"0. 萝卜丝简介",
//"1. 初始化/登录接口",
//"2. 开始对话接口",
//"3. 设置用户标签/个人资料接口",
//"4. 查询客服在线状态接口",
//"5. 聊天记录接口", // 查询未读消息记录接口, 清空本地聊天记录接口
//"6. 意见反馈接口",
//"7. 常见问题接口",
//"8. 离线留言接口",
//@"9. 未读消息条数接口"

@interface KFVisitorApiViewController ()<SFSafariViewControllerDelegate>

@property(nonatomic, strong) NSArray *apisArray;

@end

@implementation KFVisitorApiViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"访客端接口";
    //
    self.apisArray = @[ @"1. 开始新会话接口",
                        @"2. 设置用户信息接口",
                        @"3. 查询在线状态接口",
                        @"4. 会话历史记录接口",
                        @"5. 网页形式接入"
                        ];
    //
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notifyOAuthResult:) name:BD_NOTIFICATION_OAUTH_RESULT object:nil];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // Return the number of rows in the section.
    return [self.apisArray count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    // Configure the cell...
    if (!cell){
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    }
    
    [cell.textLabel setText:[self.apisArray objectAtIndex:indexPath.row]];
    
    return cell;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    //
    UIViewController *viewController = nil;
    if (indexPath.row == 0) {
        viewController = [[KFVisitorChatViewController alloc] init];
    } else if (indexPath.row == 1) {
        viewController = [[KFVisitorProfileViewController alloc] initWithStyle:UITableViewStyleGrouped];
    } else if (indexPath.row == 2) {
        viewController = [[KFVisitorStatusViewController alloc] initWithStyle:UITableViewStyleGrouped];
    } else if (indexPath.row == 3) {
        viewController = [[KFVisitorThreadViewController alloc] init];
    } else if (indexPath.row == 4) {
        // 注意: 登录后台->所有设置->所有客服->工作组->获取代码 获取相应URL
        NSURL *url = [NSURL URLWithString:@"https://vip.bytedesk.com/chat?uid=201808221551193&wid=201807171659201&type=workGroup&aid=&ph=ph"];
        SFSafariViewController *safariVC = [[SFSafariViewController alloc] initWithURL:url];
        safariVC.delegate = self;
        
        // 建议
        [self presentViewController:safariVC animated:YES completion:nil];
        return;
    }
    viewController.title = [self.apisArray objectAtIndex:indexPath.row];
    viewController.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:viewController animated:YES];
}

#pragma mark - 通知 selector

- (void)notifyOAuthResult:(NSNotification *)notification {
    NSLog(@"%s", __PRETTY_FUNCTION__);
    //
}

#pragma mark - SFSafariViewControllerDelegate
//加载完成
- (void)safariViewController:(SFSafariViewController *)controller didCompleteInitialLoad:(BOOL)didLoadSuccessfully {
    NSLog(@"%s", __PRETTY_FUNCTION__);
}

//点击左上角的done
- (void)safariViewControllerDidFinish:(SFSafariViewController *)controller {
    NSLog(@"%s", __PRETTY_FUNCTION__);
}


@end





