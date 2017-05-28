//
//  QqcComFuncDef.h
//  QqcBaseFramework
//
//  Created by hc on 15/2/4.
//  Copyright (c) 2015年 Qqc. All rights reserved.
//

#ifndef QqcBaseFramework_QqcComFuncDef_h
#define QqcBaseFramework_QqcComFuncDef_h

//获取医随身服务器其它大小图片
#define img_with_size(_origin_, _size_) [((NSString*)_origin_) stringByReplacingOccurrencesOfString:@"default" withString:_size_]

//字符串空值判断
#define str_is_exist_qqc(_str_)     (_str_ && ![_str_ isEqualToString:@""])

//NSInteger 2 NSString
#define str_from_int(_int_)  [NSString stringWithFormat:@"%ld", (long)_int_]

//把字符串连接转换成NSURL对象
#define url_from_str(_str_) [NSURL URLWithString:_str_]

//类名称
#define name_class_qqc NSStringFromClass([self class])

//App应用名称
#define name_diplay_app_qqc [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleDisplayName"]

//获取bundle
#define bundle_with_name(_name_) [NSBundle bundleWithPath:[[NSBundle mainBundle] pathForResource:_name_ ofType:@"bundle"]]

//从某个bundle中获取nib
#define nib_with_name_from_somebundle(_nibName_, _bundleName_) \
UINib* nib = nil; \
if (str_is_exist_qqc(_bundleName_)) { \
    nib = [UINib nibWithNibName:_nibName_ bundle:bundle_with_name(_bundleName_)]; \
}else{ \
    nib = [UINib nibWithNibName:_nibName_ bundle:[NSBundle mainBundle]]; \
}\
return nib;

//通过名字获取image(有缓存[NSBundle mainBundle])
#define image_with_name(_name_) [UIImage imageNamed:_name_];

//通过名字,从文件中获取image（无缓存[NSBundle mainBundle]）
#define image_from_file_with_name(_name_) \
UIImage* imageRet;  \
NSString* strName;  \
NSString* strType;  \
NSRange rang = [strFullName rangeOfString:@"." options:NSBackwardsSearch];  \
if (rang.length > 0)    \
{   \
    strName = [_name_ substringToIndex:rang.location];  \
    \
    if ([UIScreen mainScreen].scale == 2) { \
        strName = [strName stringByAppendingString:@"@2x"]; \
    }   \
    else if([UIScreen mainScreen].scale == 3)   \
    {   \
        strName = [strName stringByAppendingString:@"@3x"]; \
    }   \
        \
    strType = [strFullName substringFromIndex:rang.location+1]; \
}else{  \
    strName = strFullName;  \
    strType = @"png";   \
}   \
    \
NSString* strImgPath = [[NSBundle mainBundle] pathForResource:strName ofType:strType];  \
imageRet = [UIImage imageWithContentsOfFile:strImgPath];    \
return imageRet;


//从某个bundle中获取image（有缓存,某个bundle）
#define image_with_name_from_somebundle(_imageName_, _bundleName_)  \
UIImage* imageRet = nil;    \
NSBundle* bundle = bundle_with_name(_bundleName_);  \
if (bundle) {   \
    imageRet = [UIImage imageNamed:_imageName_ inBundle:bundle compatibleWithTraitCollection:nil];  \
}   \
    \
return imageRet;

//从某个bundle中通过名字,从文件中获取image（无缓存,某个bundle）
#define image_from_file_with_name_from_somebundle(_imageName_, _bundleName_)  \
UIImage* imageRet;  \
NSString* strName;  \
NSString* strType;  \
NSRange rang = [strFullName rangeOfString:@"." options:NSBackwardsSearch];  \
if (rang.length > 0)    \
{   \
strName = [_name_ substringToIndex:rang.location];  \
\
if ([UIScreen mainScreen].scale == 2) { \
strName = [strName stringByAppendingString:@"@2x"]; \
}   \
else if([UIScreen mainScreen].scale == 3)   \
{   \
strName = [strName stringByAppendingString:@"@3x"]; \
}   \
\
strType = [strFullName substringFromIndex:rang.location+1]; \
}else{  \
strName = strFullName;  \
strType = @"png";   \
}   \
\
NSString* strImgPath = [bundle_with_name(_bundleName_) pathForResource:strName ofType:strType];  \
imageRet = [UIImage imageWithContentsOfFile:strImgPath];    \
return imageRet;

//判断是否为iphone4
#define is_iphone4_qqc() (fabs((double)[[UIScreen mainScreen] bounds].size.height-(double)480.f ) < DBL_EPSILON )

//判断是否为iphone5
#define is_iphone5_qqc() (fabs((double)[[UIScreen mainScreen] bounds].size.height-(double)568.f ) < DBL_EPSILON )

//判断是否为iphone6
#define is_iphone6_qqc() (fabs((double)[[UIScreen mainScreen] bounds].size.height-(double)667.f ) < DBL_EPSILON )

//判断是否为iphone6p
#define is_iphone6p_qqc() (fabs((double)[[UIScreen mainScreen] bounds].size.height-(double)736.f ) < DBL_EPSILON )

//判断是否为ipod
#define is_ipod_qqc() ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

//判断是否为ipad
#define is_ipad_qqc() (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//获取的一个cell 类的标识
#define identity_of_cell(_strCellClassName_) [NSString stringWithFormat:@"%@Identity", _strCellClassName_]

//去掉日期中的时间部分
#define date_2_no_time(_date_) [[NSDate dateWithString:_date_ formatString:@"yyyy-MM-dd HH:mm:ss"] convertToStringWithFormat:@"yyyy-MM-dd"]

//去掉日期中的时间秒部分
#define date_2_no_second(_date_) [[NSDate dateWithString:_date_ formatString:@"yyyy-MM-dd HH:mm:ss"] convertToStringWithFormat:@"yyyy-MM-dd HH:mm"]

//去掉时间中的秒部分
#define time_2_no_second(_date_) [[NSDate dateWithString:_date_ formatString:@"HH:mm:ss"] convertToStringWithFormat:@"HH:mm"]

//从日期中获取年份
#define year_from_date(_date_) [[NSDate dateWithString:_date_ formatString:@"yyyy-MM-dd HH:mm:ss"] convertToStringWithFormat:@"yyyy"];

//从日期中获取月份
#define month_from_date(_date_) [[NSDate dateWithString:_date_ formatString:@"yyyy-MM-dd HH:mm:ss"] convertToStringWithFormat:@"MM"];

//从日期中获取日份
#define day_from_date(_date_) [[NSDate dateWithString:_date_ formatString:@"yyyy-MM-dd HH:mm:ss"] convertToStringWithFormat:@"dd"]

#endif
