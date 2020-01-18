open Core;
type layout = {
  .
  "width": float,
  "height": float,
};
type options;

module MaterialBottomTabNavigationProp = (M: {
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
    MaterialBottomTabNavigationProp({
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

  type accessibilityRole = string;
  type accessibilityStates = array(string);

  module TabBarBadge = {
    type t;
    [@bs.val] [@bs.module "./Interop"]
    external t:
      ([@bs.unwrap] [ | `Bool(bool) | `Number(int) | `String(string)]) => t =
      "identity";

    let boolean = x => t(`Bool(x));
    let number = x => t(`Number(x));
    let string = x => t(`String(x));
  };

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      ~tabBarColor: string=?,
      ~tabBarLabel: string=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarIcon: scene => React.element=?,
      ~tabBarBadge: TabBarBadge.t=?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarTestID: string=?,
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

  [@bs.module "@react-navigation/material-bottom-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps => React.element,
    } =
    "createMaterialBottomTabNavigator";

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
        ~backBehavior: [@bs.string] [
                         | `initialRoute
                         | `order
                         | `history
                         | `none
                       ]
                         =?,
        ~shifting: bool=?,
        ~labeled: bool=?,
        ~activeColor: string=?,
        ~inactiveColor: string=?,
        ~barStyle: ReactNative.Style.t=?,
        //TODO: More? https://github.com/callstack/react-native-paper/blob/bd4296116d841ed355f3dbebb40cfbc3b87a79ff/src/components/BottomNavigation.tsx#L132-L196
        unit
      ) =>
      navigatorProps =
      "";

    let make = stack##"Navigator";
  };
};
