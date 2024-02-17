#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void SimplifiedChinese()
	{
		Global.Author = u8"CowNow";
		Global.Date = u8"2024/02/01";

		Global.SwitchButton = u8"启用功能";
		Global.FeatureSettings = u8"详细设置";

		// ESP
		ESPtext.Toggle = u8"总开关";
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"方框";
		ESPtext.BoxRounding = u8"圆角化:";
		ESPtext.FilledBox = u8"填充方框";
		ESPtext.FilledAlpha = u8"填充透明度";
		ESPtext.Skeleton = u8"骨骼";
		ESPtext.HeadBox = u8"头部方框";
		ESPtext.EyeRay = u8"视线朝向";
		ESPtext.HealthBar = u8"生命栏";
		ESPtext.Weapon = u8"武器";
		ESPtext.Distance = u8"距离";
		ESPtext.PlayerName = u8"玩家名";
		ESPtext.SnapLine = u8"射线";
		ESPtext.LinePosList = u8"射线位置:";
		ESPtext.VisCheck = u8"可视检查";
		ESPtext.Preview = u8"效果预览";
		ESPtext.CollapseHead = u8"性感设置";
		ESPtext.Penis = u8"显示牛子";
		ESPtext.PenisLength = u8"牛子长度";
		ESPtext.PenisSize = u8"牛子粗细";
		ESPtext.MultiColor = u8"渐变色";
		ESPtext.MultiColTip = u8"仅在圆角度为0时显示.";
		ESPtext.Outline = u8"轮廓线";
		ESPtext.BoxType = u8"方框样式:";
		ESPtext.HealthNum = u8"生命数值";
		ESPtext.Ammo = u8"弹夹栏";
		ESPtext.ScopedESP = u8"开镜状态";
		ESPtext.ShowArmorBar = u8"盔甲栏";
		ESPtext.ArmorNum = u8"盔甲数值";
		ESPtext.RenderDistance = u8"最大绘制距离: ";

		ESPtext.BoxType_Normal = u8"正常";
		ESPtext.BoxType_Edge = u8"动态";
		ESPtext.BoxType_Corner = u8"四角";
		ESPtext.LinePos_1 = u8"顶部";
		ESPtext.LinePos_2 = u8"中心";
		ESPtext.LinePos_3 = u8"底部";

		// Aimbot
		AimbotText.Enable = u8"启用自瞄";
		AimbotText.FeatureName = u8" 瞄准辅助";
		AimbotText.HotKeyList = u8"热键        ";
		AimbotText.Toggle = u8"开关模式";
		AimbotText.DrawFov = u8"显示范围";
		AimbotText.VisCheck = u8"仅可见目标";
		AimbotText.JumpCheck = u8"仅在地面上";
		AimbotText.FovSlider = u8"FOV: ";
		AimbotText.FovMinSlider = u8"最小FOV: ";
		AimbotText.SmoothSlider = u8"平滑度: ";
		AimbotText.BoneList = u8"瞄准部位  ";
		AimbotText.Tip = u8"此功能在菜单打开时不会工作";
		AimbotText.ScopeOnly = u8"仅开镜";
		AimbotText.AimLock = u8"自动锁定";
		AimbotText.AutoShot = u8"自动开火";
		AimbotText.BulletSlider = u8"从第几发开始: ";

		// RCS
		RCStext.Toggle = u8"后坐控制";
		RCStext.Yaw = u8"水平强度: ";
		RCStext.Pitch = u8"垂直强度: ";

		// Radar
		RadarText.Toggle = u8"显示雷达";
		RadarText.FeatureName = u8" 外部雷达";
		RadarText.StyleList = u8"雷达样式";
		RadarText.CustomCheck = u8"自定义设置";
		RadarText.CrossLine = u8"十字线";
		RadarText.SizeSlider = u8"标记大小:";
		RadarText.ProportionSlider = u8"缩放比例:";
		RadarText.RangeSlider = u8"范围:";
		RadarText.AlphaSlider = u8"窗口透明度:";

		// Triggerbot
		TriggerText.Enable = u8"启用扳机";
		TriggerText.FeatureName = u8" 自动扳机";
		TriggerText.HotKeyList = u8"热键    ";
		TriggerText.Toggle = u8"保持激活";
		TriggerText.ScopeOnly = u8"仅开镜";
		TriggerText.DelaySlider = u8"延迟射击:";
		TriggerText.FakeShotSlider = u8"射击持续时间:";

		// Crosshairs
		CrosshairsText.Toggle = u8"显示准星";
		CrosshairsText.FeatureName = u8" 外部准星";
		CrosshairsText.PresetList = u8"预设";
		CrosshairsText.ColorEditor = u8"准星颜色";
		CrosshairsText.Dot = u8"中心点";
		CrosshairsText.DotSizeSlider = u8"中心点大小:";
		CrosshairsText.Outline = u8"轮廓线";
		CrosshairsText.Crossline = u8"十字线";
		CrosshairsText.hLengthSlider = u8"水平长度:";
		CrosshairsText.vLengthSilder = u8"垂直长度:";
		CrosshairsText.GapSlider = u8"间隙:";
		CrosshairsText.ThicknessSlider = u8"粗细:";
		CrosshairsText.tStyle = u8"T形准星";
		CrosshairsText.Circle = u8"圆环";
		CrosshairsText.RadiusSlider = u8"圆环半径:";
		CrosshairsText.TargetCheck = u8"瞄准变色";
		CrosshairsText.TeamCheck = u8"队伍检查";

		// Misc
		MiscText.FeatureName = u8" 杂项功能";
		MiscText.ThemeList = u8"主题配色  ";
		MiscText.StyleList = u8"窗口样式";
		MiscText.HeadshotLine = u8"爆头线";
		MiscText.SpecCheck = u8"旁观者保持运行";
		MiscText.NoFlash = u8"无视闪光弹";
		MiscText.FastStop = u8"自动急停";
		MiscText.HitSound = u8"命中音效";
		MiscText.bmbTimer = u8"C4计时器";
		MiscText.SpecList = u8"旁观者列表";
		MiscText.Bhop = u8"自动连跳";
		MiscText.Watermark = u8"水印浮窗";
		MiscText.CheatList = u8"功能列表";
		MiscText.TeamCheck = u8"队伍检查";
		MiscText.AntiRecord = u8"直播模式";
		MiscText.LanguageList = u8"语言";
		MiscText.MoneyService = u8"余额助手";
		MiscText.ShowCashSpent = u8"显示消费";
		MiscText.EnemySensor = u8"敌人发光";
		MiscText.RadarHack = u8"雷达透视";
		MiscText.FastStop = u8"快速急停";
		MiscText.VisCheckDisable = u8"此功能会干扰可视检查";
		MiscText.NoSmoke = u8"关闭烟雾弹";
		MiscText.SmokeColor = u8"烟雾弹颜色";
		MiscText.fovchanger = u8"视角宽度: ";
		MiscText.ForceScope = u8"右键开镜";
		MiscText.FlashImmunity = u8"闪光免疫程度: ";

		MiscText.FakeDuck = u8"假蹲";

		MiscText.LanguageList = u8"语言选择  ";

		// Config Menu
		ConfigText.FeatureName = u8" 参数配置";
		ConfigText.MyConfigs = u8"我的配置";
		ConfigText.Load = u8"加载选中";
		ConfigText.Save = u8"保存选中";
		ConfigText.Delete = u8"删除选中";
		ConfigText.Reset = u8"重置配置";
		ConfigText.Create = u8"创建配置";
		ConfigText.OpenFolder = u8"打开文件夹";
		ConfigText.SeparateLine = u8"新建配置";
		ConfigText.AuthorName = u8"作者";
		ConfigText.ConfigName = u8"配置名";

		// Readme Menu
		ReadMeText.FeatureName = u8" 其他信息";
		ReadMeText.LastUpdate = u8"最后更新: ";
		ReadMeText.SourceButton = u8"开源代码";
		ReadMeText.DiscordButton = u8"加入Discord";
		ReadMeText.OffsetsTitle = u8"相关基址: ";
	}
}
