open Core;

type options;

module DrawerNavigationProp = (M: {
                                 type params;
                                 type options;
                               }) => {
  include NavigationScreenProp(M);

  type t = navigation;

  [@bs.send] external openDrawer: t => unit = "openDrawer";
  [@bs.send] external closeDrawer: t => unit = "closeDrawer";
  [@bs.send] external toggleDrawer: t => unit = "toggleDrawer";
};

module Make = (M: {type params;}) => {
  module Navigation =
    DrawerNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    route: route(M.params),
    index: int,
    focused: bool,
    tintColor: option(string),
  };

  class type contentOptions = {
    pub items: array(route(M.params));
    pub activeItemKey: option(Js.nullable(string));
    pub activeTintColor: option(string);
    pub activeBackgroundColor: option(string);
    pub inactiveTintColor: option(string);
    pub inactiveBackgroundColor: option(string);
    pub itemsContainerStyle: option(ReactNative.Style.t);
    pub itemStyle: option(ReactNative.Style.t);
    pub labelStyle: option(ReactNative.Style.t);
    pub activeLabelStyle: option(ReactNative.Style.t);
    pub inactiveLabelStyle: option(ReactNative.Style.t);
    pub iconContainerStyle: option(ReactNative.Style.t);
  };

  class type virtual drawerNavigationItemsProps = {
    as 'self;
    constraint 'self = #contentOptions;
    pub drawerPosition: string;
    pub getLabel: scene => React.element;
    pub renderIcon: scene => React.element;
    pub onItemPress: scene => unit;
  };

  class type virtual contentComponentProps = {
    as 'self;
    constraint 'self = #drawerNavigationItemsProps;
    pub navigation: navigation;
    pub drawerOpenProgress: animatedNode;
  };

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      ~drawerLabel: scene => React.element=?,
      ~drawerIcon: scene => React.element=?,
      ~drawerLockMode: [@bs.string] [
                         | `unlocked
                         | [@bs.as "locked-closed"] `lockedClosed
                         | [@bs.as "locked-open"] `lockedOpen
                       ]
                         =?,
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

  [@bs.module "@react-navigation/drawer"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps => React.element,
    } =
    "createDrawerNavigator";

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
        //DrawerNavigationConfig
        ~drawerBackgroundColor: string=?,
        ~drawerPosition: [@bs.string] [ | `left | `right]=?,
        ~drawerType: [@bs.string] [ | `front | `back | `slide]=?,
        /*
         ~drawerWidth: [@bs.unwrap] [
                         | `Static(float)
                         | `Dynamic(unit => float)
                       ]

                       */
        ~drawerWidth: unit => float,
        ~edgeWidth: float=?,
        ~hideStatusBar: bool=?,
        ~keyboardDismissMode: [@bs.string] [
                                | [@bs.as "on-drag"] `onDrag
                                | `none
                              ]
                                =?,
        ~minSwipeDistance: float=?,
        ~overlayColor: string=?,
        ~statusBarAnimation: [@bs.string] [ | `slide | `none | `fade]=?,
        //TODO: ~gestureHandlerProps: React.ComponentProps<typeof PanGestureHandler>;
        ~_lazy: bool=?,
        ~unmountInactiveRoutes: bool=?,
        ~contentComponent: React.component(Js.t(contentComponentProps))=?,
        ~contentOptions: Js.t(contentOptions)=?,
        ~sceneContainerStyle: ReactNative.Style.t=?,
        ~style: ReactNative.Style.t=?,
        unit
      ) =>
      navigatorProps =
      "";

    let make = stack##"Navigator";
  };
};
