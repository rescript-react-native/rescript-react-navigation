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

  type any;
  type layout = {
    width: float,
    height: float,
  };
  type layouts = {
    screen: layout,
    title: option(layout),
    leftLabel: option(layout),
  };
  type stackHeaderInterpolation = {progress: animatedNode};
  type stackHeaderInterpolationProps = {
    current: stackHeaderInterpolation,
    next: option(stackHeaderInterpolation),
    layouts,
  };
  type stackHeaderInterpolatedStyle = {
    leftLabelStyle: option(any),
    leftButtonStyle: option(any),
    rightButtonStyle: option(any),
    titleStyle: option(any),
    backgroundStyle: option(any),
  };

  type layoutChangeEvent;
  type stackHeaderStyleInterpolator =
    stackHeaderInterpolationProps => stackHeaderInterpolatedStyle;

  module HeaderTitle = {
    type t;

    type headerTitleProps = {
      onLayout: layoutChangeEvent => unit,
      allowFontScaling: option(bool),
      style: option(ReactNative.Style.t), //textStyle
      children: option(string),
    };

    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [ | `String(string) | `Render(headerTitleProps => React.element)]
      ) =>
      t =
      "identity";

    let string = s => t(`String(s));
    let render = x => t(`Render(x));
  };

  type mode = string; //TODO: [ | `float | `screen | `none]

  module Header = {
    type descriptor = {
      render: unit => React.element,
      options,
      navigation,
    };
    type progress = {
      current: animatedNode,
      next: option(animatedNode),
      previous: option(animatedNode),
    };
    type headerProps('params) = {
      mode,
      style: ReactNative.Style.t,
      /* extends NavigationSceneRendererProps */
      layout,
      scene: scene(Core.route('params)),
      previous: option(scene(Core.route('params))),
      navigation,
      styleInterpolator: stackHeaderStyleInterpolator,
    }
    and scene('t) = {
      route: 't,
      descriptor,
      progress,
    };

    type t;
    [@bs.val] [@bs.module "./Interop"]
    external t:
      (
      [@bs.unwrap]
      [
        | `Render(headerProps('params) => React.element)
        | `Null(Js.null(unit))
      ]
      ) =>
      t =
      "identity";

    let render = x => t(`Render(x));

    let null = t(`Null(Js.Null.empty));
  };

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      ~header: Header.t=?,
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
        ~drawerContent: React.component(Js.t(contentComponentProps))=?,
        ~drawerContentOptions: Js.t(contentOptions)=?,
        ~sceneContainerStyle: ReactNative.Style.t=?,
        ~style: ReactNative.Style.t=?,
        unit
      ) =>
      navigatorProps =
      "";

    let make = stack##"Navigator";
  };
};
