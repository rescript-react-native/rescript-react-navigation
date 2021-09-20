open Core

type options

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

  type animatedNode = ReactNative.Animated.Value.t

  type scene = {
    route: route<M.params>,
    index: int,
    focused: bool,
    tintColor: option<string>,
  }

  type drawerLabelProps = {
    focused: bool,
    color: string,
  }
  type drawerIconProps = {
    focused: bool,
    color: string,
    size: float,
  }

  type contentOptions = {
    "items": array<route<M.params>>,
    "activeItemKey": option<Js.nullable<string>>,
    "activeTintColor": option<string>,
    "activeBackgroundColor": option<string>,
    "inactiveTintColor": option<string>,
    "inactiveBackgroundColor": option<string>,
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

  @obj
  external options: (
    ~title: string=?,
    ~_lazy: bool=?,
    ~drawerLabel: drawerLabelProps => React.element=?,
    ~drawerIcon: drawerIconProps => React.element=?,
    ~drawerActiveTintColor: string=?,
    ~drawerActiveBackgroundColor: string=?,
    ~drawerInactiveTintColor: string=?,
    ~drawerInactiveBackgroundColor: string=?,
    ~drawerItemStyle: ReactNative.Style.t=?,
    ~drawerLabelStyle: ReactNative.Style.t=?,
    ~drawerContentContainerStyle: ReactNative.Style.t=?,
    ~drawerContentStyle: ReactNative.Style.t=?,
    ~drawerStyle: ReactNative.Style.t=?,
    ~drawerPosition: [#left | #right]=?,
    ~drawerType: [#front | #back | #slide | #permanent]=?,
    ~drawerHideStatusBarOnOpen: bool=?,
    ~drawerStatusBarAnimation: [#slide | #fade | #none]=?,
    ~overlayColor: string=?,
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
    unit,
  ) => options = ""
  // TODO Header options: https://reactnavigation.org/docs/drawer-navigator/#header-related-options
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

  type screenProps

  type groupProps

  @module("@react-navigation/drawer")
  external make: unit => {
    "Navigator": navigatorProps => React.element,
    "Screen": screenProps => React.element,
    "Group": groupProps => React.element,
  } = "createDrawerNavigator"

  let stack = make()

  module Screen = {
    @obj
    external makeProps: (
      ~name: string,
      ~options: optionsCallback=?,
      ~initialParams: M.params=?,
      ~component: React.component<{"navigation": navigation, "route": route<M.params>}>,
      ~key: string=?,
      unit,
    ) => screenProps = ""
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
    ) => screenProps = ""
    let make = stack["Group"]
  }
}
