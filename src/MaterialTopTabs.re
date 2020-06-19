open Core;

type layout = {
  width: float,
  height: float,
};
type options;

module MaterialTopTabNavigationProp = (M: {
                                         type params;
                                         type options;
                                       }) => {
  include NavigationScreenProp(M);

  type t = navigation;

  [@bs.send] external jumpTo: (t, string) => unit = "jumpTo";
  [@bs.send]
  external jumpToWithParams: (t, string, M.params) => unit = "jumpTo";
};

module Make = (M: {type params;}) => {
  module Navigation =
    MaterialTopTabNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    .
    "route": route(M.params),
    "focused": bool,
    "tintColor": string,
  };

  class type virtual tabBar = {
    pub scrollEnabled: option(bool);
    pub bounces: option(bool);
    //pub navigationState: navigationState(M.params);
    //pub activeColor: option(string);
    //pub inactiveColor: option(string);
    pub pressColor: option(string);
    pub pressOpacity: option(float);
    //pub getLabelText: scene => Js.nullable(string);
    pub getAccessible: scene => Js.nullable(bool);
    //pub getAccessibilityLabel: scene => Js.nullable(string);
    //pub getTestID: scene => Js.nullable(string);
    //TODO: render: https://github.com/react-native-community/react-native-tab-view/blob/64e03bf14b0fac9c3bccd684bf31a04ecf19c50d/src/TabBar.tsx#L38-L51
    //pub onTabPress: option(scene => unit);
    //pub onTabLongPress: option(scene => unit);
    pub tabStyle: option(ReactNative.Style.t);
    pub indicatorStyle: option(ReactNative.Style.t);
    pub indicatorContainerStyle: option(ReactNative.Style.t);
    pub labelStyle: option(ReactNative.Style.t);
    pub contentContainerStyle: option(ReactNative.Style.t);
    pub style: option(ReactNative.Style.t);
  };

  class type virtual materialTopTabBarOptions = {
    as 'self;
    constraint 'self = #tabBar;
    pub activeTintColor: option(string);
    pub inactiveTintColor: option(string);
    pub iconStyle: option(ReactNative.Style.t);
    pub showLabel: option(bool);
    pub showIcon: option(bool);
    pub upperCaseLabel: option(bool);
    pub allowFontScaling: option(bool);
  };

  type accessibilityRole = string;
  type accessibilityStates = array(string);

  type routeOptions = {route: route(M.params)};

  class type virtual materialTopTabBarProps = {
    as 'self;
    constraint 'self = #materialTopTabBarOptions;
    pub state: navigationState(M.params);
    pub navigation: navigation;
    //pub getLabelText: routeOptions => ...;
    pub getAccessibilityLabel: routeOptions => Js.nullable(string);
    pub getTestID: routeOptions => Js.nullable(string);
    pub onTabPress:
      {
        .
        "route": route(M.params),
        [@bs.meth] "preventDefault": unit => unit,
      } =>
      unit;
    pub onTabLongPress: routeOptions => unit;
    pub tabBarPosition: string; //`top | `bottom
    //SceneRendererProps
    pub layout: layout;
    pub position: animatedNode;
  };

  [@bs.obj]
  external materialTopTabBarOptions:
    (
      ~activeTintColor: string=?,
      ~inactiveTintColor: string=?,
      ~iconStyle: ReactNative.Style.t=?,
      ~showLabel: bool=?,
      ~showIcon: bool=?,
      ~upperCaseLabel: bool=?,
      ~allowFontScaling: bool=?,
      ~scrollEnabled: bool=?,
      ~bounces: bool=?,
      ~pressColor: string=?,
      ~pressOpacity: float=?,
      ~getAccessible: Js.nullable(bool)=?,
      ~tabStyle: ReactNative.Style.t=?,
      ~indicatorStyle: ReactNative.Style.t=?,
      ~indicatorContainerStyle: ReactNative.Style.t=?,
      ~labelStyle: ReactNative.Style.t=?,
      ~contentContainerStyle: ReactNative.Style.t=?,
      ~style: ReactNative.Style.t=?,
      unit
    ) =>
    materialTopTabBarOptions =
    "";

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarLabel: scene => React.element=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarIcon: scene => React.element=?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarTestID: string=?,
      ~tabBarVisible: bool=?,
      unit
    ) =>
    options =
    "";

  type optionsProps = {
    navigation,
    route: route(M.params),
  };

  type optionsCallback = optionsProps => options;

  type navigatorProps;

  type screenProps;

  [@bs.module "@react-navigation/material-top-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps => React.element,
    } =
    "createMaterialTopTabNavigator";

  let stack = make();

  module Screen = {
    [@bs.obj]
    external makeProps:
      (
        ~name: string,
        ~options: optionsCallback=?,
        ~initialParams: M.params=?,
        ~component: React.component({. "navigation": navigation}),
        unit
      ) =>
      screenProps =
      "";
    let make = stack##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionsCallback=?,
        ~children: React.element,
        ~lazyPlaceholderComponent: React.component({
                                     .
                                     "route": route(M.params),
                                   })
                                     =?,
        ~tabBar: React.component(Js.t(materialTopTabBarProps))=?,
        ~tabBarOptions: materialTopTabBarOptions=?,
        ~tabBarPosition: [@bs.string] [ | `top | `bottom]=?,
        unit
      ) =>
      navigatorProps =
      "";

    let make = stack##"Navigator";
  };
};
