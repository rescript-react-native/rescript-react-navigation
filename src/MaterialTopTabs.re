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
  type nonrec route = route(M.params);
  module Navigation =
    MaterialTopTabNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    focused: bool,
    color: string,
  };

  type descriptors;

  class type virtual tabBar = {
    pub scrollEnabled: option(bool);
    //pub navigationState: navigationState(M.params);
    //pub activeColor: option(string);
    //pub inactiveColor: option(string);
    pub pressColor: option(string);
    pub pressOpacity: option(float);
    //pub getLabelText: scene => Js.nullable(string);
    //pub getAccessibilityLabel: scene => Js.nullable(string);
    //pub getTestID: scene => Js.nullable(string);
    //TODO: render: https://github.com/react-native-community/react-native-tab-view/blob/64e03bf14b0fac9c3bccd684bf31a04ecf19c50d/src/TabBar.tsx#L38-L51
    //pub onTabPress: option(scene => unit);
    //pub onTabLongPress: option(scene => unit);
    pub tabStyle: option(ReactNative.Style.t);
    pub indicatorStyle: option(ReactNative.Style.t);
    pub labelStyle: option(ReactNative.Style.t);
    pub style: option(ReactNative.Style.t);
    pub renderIndicator: option(React.component({. "route": route}));
  };

  class type virtual materialTopTabBarOptions = {
    as 'self;
    constraint 'self = #tabBar;
    pub activeTintColor: option(string);
    pub inactiveTintColor: option(string);
    pub iconStyle: option(ReactNative.Style.t);
    pub showLabel: option(bool);
    pub showIcon: option(bool);
    pub allowFontScaling: option(bool);
  };

  type accessibilityRole = string;
  type accessibilityStates = array(string);

  type routeOptions = {route};

  class type virtual materialTopTabBarProps = {
    as 'self;
    constraint 'self = #materialTopTabBarOptions;
    pub state: navigationState(M.params);
    pub navigation: navigation;
    pub descriptors: descriptors;
    //pub getLabelText: routeOptions => ...;
    pub getAccessibilityLabel: routeOptions => Js.nullable(string);
    pub getTestID: routeOptions => Js.nullable(string);
    pub onTabPress:
      {
        .
        "route": route,
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
      ~allowFontScaling: bool=?,
      ~scrollEnabled: bool=?,
      ~pressColor: string=?,
      ~pressOpacity: float=?,
      ~tabStyle: ReactNative.Style.t=?,
      ~indicatorStyle: ReactNative.Style.t=?,
      ~labelStyle: ReactNative.Style.t=?,
      ~style: ReactNative.Style.t=?,
      ~renderIndicator: React.component({. "route": route})=?,
      unit
    ) =>
    materialTopTabBarOptions;

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
      unit
    ) =>
    options;

  type optionsProps = {
    navigation,
    route,
  };

  type optionsCallback = optionsProps => options;

  type navigatorProps = {
    initialRouteName: option(string),
    screenOptions: option(optionsCallback),
    _lazy: option(bool),
    lazyPreloadDistance: option(int),
    lazyPlaceholder: option(React.component({. "route": route})),
    tabBar: option(React.component(Js.t(materialTopTabBarProps))),
    tabBarOptions: option(materialTopTabBarOptions),
    tabBarPosition: option(string),
    backBehavior: option(string),
    removeClippedSubviews: option(bool),
    keyboardDismissMode: option(string),
    swipeEnabled: option(bool),
    swipeVelocityImpact: option(float),
    sceneContainerStyle: option(ReactNative.Style.t),
    style: option(ReactNative.Style.t),
  };

  type renderCallbackProp = {
    navigation,
    route,
  };

  type screenProps('params) = {
    name: string,
    options: option(optionsCallback),
    initialParams: option('params),
    component:
      option(
        React.component({
          .
          "navigation": navigation,
          "route": route,
        }),
      ),
    children: option(renderCallbackProp => React.element),
  };

  [@bs.module "@react-navigation/material-top-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps(M.params) => React.element,
    } =
    "createMaterialTopTabNavigator";

  let materialTopTabs = make();

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
      screenProps(M.params);
    let make = materialTopTabs##"Screen";
  };

  module ScreenWithCallback = {
    [@bs.obj]
    external makeProps:
      (
        ~name: string,
        ~options: optionsCallback=?,
        ~initialParams: M.params=?,
        ~children: renderCallbackProp => React.element,
        unit
      ) =>
      screenProps(M.params);
    let make = materialTopTabs##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionsCallback=?,
        ~children: React.element,
        ~backBehavior: [@bs.string] [
                         | `initialRoute
                         | `order
                         | `history
                         | `none
                       ]
                         =?,
        ~_lazy: bool=?,
        ~lazyPreloadDistance: int=?,
        ~lazyPlaceholder: React.component({. "route": route})=?,
        ~tabBar: React.component(Js.t(materialTopTabBarProps))=?,
        ~tabBarOptions: materialTopTabBarOptions=?,
        ~tabBarPosition: [@bs.string] [ | `top | `bottom]=?,
        ~removeClippedSubviews: bool=?,
        ~keyboardDismissMode: [@bs.string] [
                                | `auto
                                | [@bs.as "on-drag"] `onDrag
                                | `none
                              ]
                                =?,
        ~swipeEnabled: bool=?,
        ~swipeVelocityImpact: float=?,
        ~sceneContainerStyle: ReactNative.Style.t=?,
        ~style: ReactNative.Style.t=?,
        unit
      ) =>
      navigatorProps;

    let make = materialTopTabs##"Navigator";
  };

  module MaterialTopTabBar = {
    [@bs.module "@react-navigation/material-top-tabs"] [@react.component]
    external make:
      (
        ~state: navigationState(M.params),
        ~navigation: navigation,
        ~descriptors: descriptors,
        ~activeTintColor: string=?,
        ~inactiveTintColor: string=?,
        ~iconStyle: ReactNative.Style.t=?,
        ~showLabel: bool=?,
        ~showIcon: bool=?,
        ~allowFontScaling: bool=?,
        ~scrollEnabled: bool=?,
        ~pressColor: string=?,
        ~pressOpacity: float=?,
        ~tabStyle: ReactNative.Style.t=?,
        ~indicatorStyle: ReactNative.Style.t=?,
        ~labelStyle: ReactNative.Style.t=?,
        ~style: ReactNative.Style.t=?,
        ~renderIndicator: React.component({. "route": route})=?,
        unit
      ) =>
      React.element =
      "MaterialTopTabBar";
  };
};
