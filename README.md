# ThirdPersonStudy

基于 Unreal Engine 5.5 的第三人称练习项目，当前主要用于学习第三人称模板、Steam Online Subsystem、多人会话创建与加入流程。

## 项目状态

当前项目已经完成基础第三人称模板搭建，并开始接入多人联机功能。

已完成：

- UE 5.5 C++ 第三人称项目基础结构
- 第三人称角色移动、镜头和 Enhanced Input 输入绑定
- `ThirdPersonMap` 和 `Lobby` 两个地图
- Steam Online Subsystem 相关依赖接入
- `MultiplayerSessions` 插件雏形
- `WBP_Menu` 菜单资产
- Host 按钮通过 `UMultiplayersSessionsSubsystem` 创建 Session
- 创建 Session 完成后通过自定义委托通知菜单
- Session 创建成功后跳转到 `Lobby` 地图
- Windows Development 打包流程验证

进行中：

- 将角色类中的 Session 逻辑迁移到 `MultiplayerSessions` 插件
- 补全 Find / Join / Destroy / Start Session 流程
- 修正 Steam NetDriver 配置并完成双客户端联机测试

## 环境要求

- Unreal Engine 5.5
- Visual Studio 2022，安装 C++ 游戏开发相关组件
- Windows 64-bit
- Steam 客户端，联机测试时需要

## 目录结构

```text
Config/                         项目配置文件
Content/                        游戏资产、地图、蓝图和 Starter Content
Plugins/MultiplayerSessions/    多人会话插件
Source/ThirdPersonStudy/        主游戏模块 C++ 源码
ThirdPersonStudy.uproject        Unreal 项目文件
```

以下目录为生成内容，已被 Git 忽略：

```text
Binaries/
Build/
DerivedDataCache/
Intermediate/
Saved/
.vs/
.idea/
```

## 打开项目

1. 安装 Unreal Engine 5.5。
2. 双击 `ThirdPersonStudy.uproject` 打开项目。
3. 如果提示重新生成项目文件或编译模块，选择确认。
4. 在编辑器中打开 `Content/ThirdPerson/Maps/ThirdPersonMap` 或 `Content/ThirdPerson/Maps/Lobby`。

## 编译

可以在 Unreal Editor 中直接编译，也可以使用 Visual Studio 打开 `ThirdPersonStudy.sln` 后编译 `Development Editor` 配置。

## 打包

当前打包配置位于 `Config/DefaultGame.ini`，已包含：

- `/Game/ThirdPerson/Maps/Lobby`
- `/Game/ThirdPerson/Maps/ThirdPersonMap`

在 Unreal Editor 中使用：

```text
Platforms -> Windows -> Package Project
```

## 多人联机说明

当前项目接入了 `OnlineSubsystemSteam`，并使用 Steam 测试 App ID：

```text
480
```

注意：多人联机功能仍在开发中。目前 Host 创建 Session 的流程已经开始走 `UMultiplayersSessionsSubsystem`，并通过 `FMultiplayerOnCreateSessionComplete` 回调通知菜单。Session 创建成功后菜单会执行 `ServerTravel` 跳转到 `Lobby`。

目前仍未完成：

- 查找 Session
- 加入 Session
- 销毁已有 Session 后重新创建
- 开始 Session
- 双客户端 Steam 联机验证

主角色类中仍保留了早期的会话测试代码，后续目标是统一迁移到插件中的 `UMultiplayersSessionsSubsystem`。

## Git 说明

仓库已配置 `.gitignore` 和 `.gitattributes`，Unreal 生成目录不会进入版本库，`.uasset`、`.umap` 等资产按二进制文件处理。

项目中包含较大的 Unreal 资产。GitHub 已能接收当前文件，但后续如果资产继续增大，建议接入 Git LFS。

## 下一步计划

- 修复 `DefaultEngine.ini` 中 Steam NetDriver 配置
- 补全 `MultiplayerSessions` 插件的查找和加入会话逻辑
- 让菜单 Join 完整走 Subsystem
- 处理已有 Session 时的 Destroy -> Create 流程
- 移除角色类中临时的会话测试代码
- 完成双客户端 Host / Join / Lobby 跳转测试
