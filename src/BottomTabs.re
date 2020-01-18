open Core;

type options;

module BottomTabNavigationProp = (M: {
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
    BottomTabNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    index: int,
    focused: bool,
    tintColor: string,
  };

  type labelPositionArgs = {deviceOrientation: string};

  class type virtual baseBottomTabBarOptions = {
    pub keyboardHidesTabBar: option(bool);
    pub activeBackgroundColor: option(string);
    pub inactiveBackgroundColor: option(string);
    pub allowFontScaling: option(bool);
    pub showLabel: option(bool);
    pub showIcon: option(bool);
    pub labelStyle: option(ReactNative.Style.t);
    pub tabStyle: option(ReactNative.Style.t);
    pub labelPosition: option(labelPositionArgs => string);
    pub adaptive: option(bool);
    pub style: option(ReactNative.Style.t);
  };

  class type virtual bottomTabBarOptions = {
    as 'self;
    constraint 'self = #baseBottomTabBarOptions;
    pub activeTintColor: option(string);
    pub inactiveTintColor: option(string);
  };

  type accessibilityRole = string;
  type accessibilityStates = array(string);
  type routeArgs = {route: route(M.params)};
  type renderIconArgs = {
    route: route(M.params),
    focused: bool,
    tintColor: string,
    horizontal: bool,
  };
  class type virtual bottomTabBarProps = {
    as 'self;
    constraint 'self = #baseBottomTabBarOptions;
    pub state: navigationState(M.params);
    pub navigation: navigation;
    pub onTabPress: routeArgs => unit;
    pub onTabLongPress: routeArgs => unit;
    pub getAccessibilityLabel: routeArgs => Js.nullable(string);
    pub getAccessibilityRole: routeArgs => Js.nullable(accessibilityRole);
    pub getAccessibilityStates: routeArgs => Js.nullable(accessibilityStates);
    pub getButtonComponent: routeArgs => Js.nullable(React.element);
    //pub getLabelText: routeArgs => ...;
    pub getTestID: routeArgs => Js.nullable(string);
    pub renderIcon: renderIconArgs => React.element;
    pub activeTintColor: string;
    pub inactiveTintColor: string;
  };

  [@bs.obj]
  external bottomTabBarOptions:
    (
      ~keyboardHidesTabBar: bool=?,
      ~activeTintColor: string=?,
      ~inactiveTintColor: string=?,
      ~activeBackgroundColor: string=?,
      ~inactiveBackgroundColor: string=?,
      ~allowFontScaling: bool=?,
      ~showLabel: bool=?,
      ~showIcon: bool=?,
      ~labelStyle: ReactNative.Style.t=?,
      ~tabStyle: ReactNative.Style.t=?,
      ~labelPosition: labelPositionArgs => string=?,
      ~adaptive: bool=?,
      ~style: ReactNative.Style.t=?,
      unit
    ) =>
    bottomTabBarOptions =
    "";

  type tabBarLabelArgs = {
    focused: bool,
    color: string,
  };
  type tabBarIconArgs = {
    focused: bool,
    color: string,
    size: float,
  };
  [@bs.obj]
  external options:
    (
      ~title: string=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarLabel: tabBarLabelArgs => React.element=?,
      ~tabBarIcon: tabBarIconArgs => React.element=?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarTestID: string=?,
      ~tabBarVisible: bool=?,
      ~tabBarButtonComponent: React.element=?,
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

  [@bs.module "@react-navigation/bottom-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps => React.element,
    } =
    "createBottomTabNavigator";

  let bottomTabs = make();

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
    let make = bottomTabs##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionsCallback=?,
        ~children: React.element,
        ~_lazy: bool=?,
        ~tabBarComponent: React.component(Js.t(bottomTabBarProps))=?,
        ~tabBarOptions: bottomTabBarOptions=?,
        unit
      ) =>
      navigatorProps =
      "";

    let make = bottomTabs##"Navigator";
  };
};
