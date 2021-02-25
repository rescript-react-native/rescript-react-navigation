open Core

@module("react-native-screens")
external enableScreens: unit => unit = "enableScreens"

type options

module NativeStackNavigationScreenProp = (
  M: {
    type params
    type options
  },
) => {
  include NavigationScreenProp(M)

  type t = navigation

  @send external push: (t, string) => unit = "push"
  @send external pushWithParams: (t, string, M.params) => unit = "push"

  @send external pop: (t, ~count: int=?, unit) => unit = "pop"

  @send external popToTop: (t, unit) => unit = "popToTop"
}

module Make = (
  M: {
    type params
  },
) => {
  type route = route<M.params>
  module Navigation = NativeStackNavigationScreenProp({
    include M
    type options = options
  })

  type headerBackTitleStyle = {fontFamily: option<string>, fontSize: option<float>}
  type headerLargeStyle = {backgroundColor: option<ReactNative.Color.t>}
  type headerLargeTitleStyle = {
    fontFamily: option<string>,
    fontSize: option<float>,
    color: option<ReactNative.Color.t>,
  }
  type blurEffect = [
    | #extraLight
    | #light
    | #dark
    | #regular
    | #prominent
    | #systemUltraThinMaterial
    | #systemThinMaterial
    | #systemMaterial
    | #systemThickMaterial
    | #systemChromeMaterial
    | #systemUltraThinMaterialLight
    | #systemThinMaterialLight
    | #systemMaterialLight
    | #systemThickMaterialLight
    | #systemChromeMaterialLight
    | #systemUltraThinMaterialDark
    | #systemThinMaterialDark
    | #systemMaterialDark
    | #systemThickMaterialDark
    | #systemChromeMaterialDark
  ]
  type headerStyle = {
    backgroundColor: option<ReactNative.Color.t>,
    blurEffect: option<blurEffect>,
  }
  type headerTitleStyle = {
    fontFamily: option<string>,
    fontSize: option<float>,
    fontWeight: string, //ReactNative.Style.fontWeight,
    color: option<ReactNative.Color.t>,
  }

  @obj
  external options: (
    ~backButtonInCustomView: bool=?,
    ~contentStyle: ReactNative.Style.t=?,
    ~direction: [#rtl | #ltr]=?,
    ~gestureEnabled: bool=?,
    ~headerBackTitle: string=?,
    ~headerBackTitleStyle: headerBackTitleStyle=?,
    ~headerBackTitleVisible: bool=?,
    ~headerCenter: unit => React.element=?,
    ~headerHideBackButton: bool=?,
    ~headerHideShadow: bool=?,
    ~headerLargeStyle: headerLargeStyle=?,
    ~headerLargeTitle: bool=?,
    ~headerLargeTitleHideShadow: bool=?,
    ~headerLargeTitleStyle: headerLargeTitleStyle=?,
    ~headerLeft: unit => React.element=?,
    ~headerRight: unit => React.element=?,
    ~headerShown: bool=?,
    ~headerStyle: headerStyle=?,
    ~headerTintColor: ReactNative.Color.t=?,
    ~headerTitle: string=?,
    ~headerTitleStyle: headerTitleStyle=?,
    ~headerTopInsetEnabled: bool=?,
    ~headerTranslucent: bool=?,
    ~replaceAnimation: [#push | #pop]=?,
    ~stackAnimation: [#default | #fade | #flip | #slide_from_right | #slide_from_left | #none]=?,
    ~stackPresentation: [
      | #push
      | #modal
      | #transparentModal
      | #containedModal
      | #containedTransparentModal
      | #fullScreenModal
      | #formSheet
    ]=?,
    ~statusBarStyle: [#auto | #inverted | #light | #dark]=?,
    ~statusBarAnimation: [#fade | #none | #slide]=?,
    ~statusBarHidden: bool=?,
    ~screenOrientation: [
      | #default
      | #all
      | #portrait
      | #portrait_up
      | #portrait_down
      | #landscape
      | #landscape_left
      | #landscape_right
    ]=?,
    ~title: string=?,
    unit,
  ) => options = ""

  type optionsProps = {
    navigation: navigation,
    route: route,
  }
  type optionsCallback = optionsProps => options

  type navigatorProps = {
    initialRouteName: option<string>,
    screenOptions: option<optionsCallback>,
  }
  type renderCallbackProp = {
    navigation: navigation,
    route: route,
  }
  type screenProps<'params> = {
    name: string,
    options: option<optionsCallback>,
    initialParams: option<'params>,
    component: option<React.component<{"navigation": navigation, "route": route}>>,
    children: option<renderCallbackProp => React.element>,
  }

  @module("react-native-screens/native-stack")
  external make: unit => {
    "Navigator": navigatorProps => React.element,
    "Screen": screenProps<M.params> => React.element,
  } = "createNativeStackNavigator"

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
    type componentProps = {navigation: navigation}
    @obj
    external makeProps: (
      ~name: string,
      ~options: optionsCallback=?,
      ~initialParams: M.params=?,
      ~component: React.component<{"navigation": navigation, "route": route}>,
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
      ~key: string=?,
      unit,
    ) => navigatorProps = ""

    let make = stack["Navigator"]
  }
}

@val
external mergeOptions: (options, options) => options = "Object.assign"
