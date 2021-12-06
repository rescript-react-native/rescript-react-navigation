open Core

type options

type layoutChangeEvent

module DrawerNavigationProp = (
  M: {
    type params
    type options
  },
) => {
  include NavigationScreenProp(M)

  type t = navigation

  @send external openDrawer: t => unit = "openDrawer"
  @send external closeDrawer: t => unit = "closeDrawer"
  @send external toggleDrawer: t => unit = "toggleDrawer"
  @send external jumpTo: (t, ~name: string, ~params: 'params=?, unit) => unit = "jumpTo"
}
module Make = (
  M: {
    type params
  },
) => {
  module Navigation = DrawerNavigationProp({
    include M
    type options = options
  })

  module HeaderTitle = {
    type t

    type headerTitleProps = {
      children: option<string>,
      allowFontScaling: option<bool>,
      tintColor: option<ReactNative.Color.t>,
      onLayout: layoutChangeEvent => unit,
      style: option<ReactNative.Style.t>, //textStyle
    }

    @val @module("./Interop")
    external t: @unwrap
    [
      | #String(string)
      | #Render(headerTitleProps => React.element)
    ] => t = "identity"

    let string = s => t(#String(s))
    let render = x => t(#Render(x))
  }

  module DrawerLabel = {
    type t

    type drawerLabelProps = {
      focused: bool,
      color: string,
    }

    @val @module("./Interop")
    external t: @unwrap
    [
      | #String(string)
      | #Render(drawerLabelProps => React.element)
    ] => t = "identity"

    let string = s => t(#String(s))
    let render = x => t(#Render(x))
  }

  type animatedNode = ReactNative.Animated.Value.t

  type scene = {
    route: route<M.params>,
    index: int,
    focused: bool,
    tintColor: option<ReactNative.Color.t>,
  }

  type drawerIconProps = {
    focused: bool,
    color: ReactNative.Color.t,
    size: float,
  }

  type contentOptions = {
    "items": array<route<M.params>>,
    "activeItemKey": option<Js.nullable<string>>,
    "activeTintColor": option<ReactNative.Color.t>,
    "activeBackgroundColor": option<ReactNative.Color.t>,
    "inactiveTintColor": option<ReactNative.Color.t>,
    "inactiveBackgroundColor": option<ReactNative.Color.t>,
    "itemsContainerStyle": option<ReactNative.Style.t>,
    "itemStyle": option<ReactNative.Style.t>,
    "labelStyle": option<ReactNative.Style.t>,
    "activeLabelStyle": option<ReactNative.Style.t>,
    "inactiveLabelStyle": option<ReactNative.Style.t>,
    "iconContainerStyle": option<ReactNative.Style.t>,
  }

  type drawerNavigationItemsProps = {
    ...contentOptions,
    "drawerPosition": string,
    "getLabel": scene => React.element,
    "renderIcon": scene => React.element,
    "onItemPress": scene => unit,
  }

  type contentComponentProps = {
    ...drawerNavigationItemsProps,
    "navigation": navigation,
    "drawerOpenProgress": animatedNode,
  }

  type headerRightOptions = {
    tintColor: option<ReactNative.Color.t>,
    pressColor: option<ReactNative.Color.t>,
    pressOpacity: option<float>,
  }

  type headerLeftOptions = {
    tintColor: option<ReactNative.Color.t>,
    pressColor: option<ReactNative.Color.t>,
    pressOpacity: option<float>,
    labelVisible: option<bool>,
  }

  type headerBackgroundOptions = {style: option<ReactNative.Style.t>}

  @obj
  external options: (
    ~title: string=?,
    ~_lazy: bool=?,
    ~drawerLabel: DrawerLabel.t=?,
    ~drawerIcon: drawerIconProps => React.element=?,
    ~drawerActiveTintColor: ReactNative.Color.t=?,
    ~drawerActiveBackgroundColor: ReactNative.Color.t=?,
    ~drawerInactiveTintColor: ReactNative.Color.t=?,
    ~drawerInactiveBackgroundColor: ReactNative.Color.t=?,
    ~drawerItemStyle: ReactNative.Style.t=?,
    ~drawerLabelStyle: ReactNative.Style.t=?,
    ~drawerContentContainerStyle: ReactNative.Style.t=?,
    ~drawerContentStyle: ReactNative.Style.t=?,
    ~drawerStyle: ReactNative.Style.t=?,
    ~drawerPosition: [#left | #right]=?,
    ~drawerType: [#front | #back | #slide | #permanent]=?,
    ~drawerHideStatusBarOnOpen: bool=?,
    ~drawerStatusBarAnimation: [#slide | #fade | #none]=?,
    ~overlayColor: ReactNative.Color.t=?,
    ~sceneContainerStyle: ReactNative.Style.t=?,
    ~gestureEnabled: bool=?,
    ~gestureHandlerProps: 'gestureHandlerProps=?,
    ~swipeEnabled: bool=?,
    ~swipeEdgeWidth: float=?,
    ~swipeMinDistance: float=?,
    ~keyboardDismissMode: @string
    [
      | @as("on-drag") #onDrag
      | #none
    ]=?,
    ~unmountOnBlur: bool=?,
    ~headerShown: bool=?,
    // ~header: Header.t=?,
    ~headerTitle: HeaderTitle.t=?,
    ~headerTitleAlign: [#left | #center]=?,
    ~headerTitleStyle: ReactNative.Style.t=?,
    ~headerTitleContainerStyle: ReactNative.Style.t=?,
    ~headerTitleAllowFontScaling: bool=?,
    ~headerLeft: headerLeftOptions => React.element=?,
    ~headerLeftLabelVisible: bool=?,
    ~headerLeftContainerStyle: ReactNative.Style.t=?,
    ~headerRight: headerRightOptions => React.element=?,
    ~headerRightContainerStyle: ReactNative.Style.t=?,
    ~headerPressColor: ReactNative.Color.t=?,
    ~headerPressOpacity: float=?,
    ~headerTintColor: ReactNative.Color.t=?,
    ~headerBackground: headerBackgroundOptions => React.element=?,
    ~headerBackgroundContainerStyle: ReactNative.Style.t=?,
    ~headerTransparent: bool=?,
    ~headerStyle: ReactNative.Style.t=?,
    ~headerShadowVisible: bool=?,
    ~headerStatusBarHeight: ReactNative.Style.size=?,
    unit,
  ) => options = ""
  // ~drawerLockMode: [@bs.string] [
  //                    | `unlocked
  //                    | [@bs.as "locked-closed"] `lockedClosed
  //                    | [@bs.as "locked-open"] `lockedOpen
  //                  ]
  //                    =?,

  type optionsProps = {
    navigation: navigation,
    route: route<M.params>,
  }

  type optionsCallback = optionsProps => options

  type navigatorProps

  type groupProps = {screenOptions: option<optionsCallback>}

  type renderCallbackProp = {
    navigation: navigation,
    route: route<M.params>,
  }

  type screenProps<'params> = {
    name: string,
    options: option<optionsCallback>,
    initialParams: option<'params>,
    component: option<React.component<{"navigation": navigation, "route": route<M.params>}>>,
    children: option<renderCallbackProp => React.element>,
  }

  @module("@react-navigation/drawer")
  external make: unit => {
    "Navigator": navigatorProps => React.element,
    "Screen": screenProps<M.params> => React.element,
    "Group": groupProps => React.element,
  } = "createDrawerNavigator"

  let stack = make()

  module ScreenWithCallback = {
    @obj
    external makeProps: (
      ~name: string,
      ~options: optionsCallback=?,
      ~initialParams: M.params=?,
      ~children: renderCallbackProp => React.element,
      ~key: string=?,
      unit,
    ) => screenProps<M.params> = ""
    let make = stack["Screen"]
  }

  module Screen = {
    @obj
    external makeProps: (
      ~name: string,
      ~options: optionsCallback=?,
      ~initialParams: M.params=?,
      ~component: React.component<{"navigation": navigation, "route": route<M.params>}>,
      ~key: string=?,
      unit,
    ) => screenProps<M.params> = ""
    let make = stack["Screen"]
  }

  module Navigator = {
    @obj
    external makeProps: (
      ~initialRouteName: string=?,
      ~screenOptions: optionsCallback=?,
      ~children: React.element,
      ~backBehavior: [#firstRoute | #initialRoute | #order | #history | #none]=?,
      ~defaultStatus: @string [@as("open") #open_ | #closed]=?,
      ~detachInactiveScreens: bool=?,
      ~useLegacyImplementation: bool=?,
      /*
      The content component receives following props by default:

      state - The navigation state of the navigator.
      navigation - The navigation object for the navigator.
      descriptors - An descriptor object containing options for the drawer screens. The options can be accessed at descriptors[route.key].options.
      progress - Reanimated Node that represents the animated position of the drawer (0 is closed; 1 is open).
 */
      ~drawerContent: React.component<contentComponentProps>=?,
      //TODO: ~gestureHandlerProps: React.ComponentProps<typeof PanGestureHandler>;
      // ~unmountInactiveRoutes: bool=?,
      // ~drawerContentOptions: Js.t<contentOptions>=?,

      ~key: string=?,
      unit,
    ) => navigatorProps = ""

    let make = stack["Navigator"]
  }

  module Group = {
    @obj
    external makeProps: (
      ~screenOptions: optionsCallback=?,
      ~children: React.element,
      ~key: string=?,
      unit,
    ) => groupProps = ""
    let make = stack["Group"]
  }
}
