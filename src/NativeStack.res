// https://reactnavigation.org/docs/native-stack-navigator/

open Core
open Elements
open ReactNative

@module("react-native-screens")
external enableScreens: unit => unit = "enableScreens"

type animation = [
  | #default
  | #fade
  | #fade_from_bottom
  | #flip
  | #simple_push
  | #slide_from_bottom
  | #slide_from_right
  | #slide_from_left
  | #none
]

type animationTypeForReplace = [#push | #pop]

type headerBackTitleStyle = {
  fontFamily?: string,
  fontSize?: float,
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

type headerLargeStyle = {backgroundColor?: Color.t}

type headerLargeTitleStyle = {
  fontFamily: option<string>,
  fontSize: option<float>,
  color: option<Color.t>,
}

type headerStyle = {backgroundColor?: Color.t}

type headerTitleStyle = {
  fontFamily?: string,
  fontSize?: float,
  fontWeight?: Style.fontWeight,
  color?: Color.t,
}

type presentation = [
  | #card
  | #modal
  | #transparentModal
  | #containedModal
  | #containedTransparentModal
  | #fullScreenModal
  | #formSheet
]

type statusBarStyle = [#auto | #inverted | #light | #dark]

type statusBarAnimation = [#fade | #none | #slide]

type orientation = [
  | #default
  | #all
  | #portrait
  | #portrait_up
  | #portrait_down
  | #landscape
  | #landscape_left
  | #landscape_right
]

type headerTitleAlign = [#left | #center]

type inputType = [
  | #text
  | #phone
  | #number
  | #email
]

type headerSearchBarOptions = {
  autoCapitalize?: TextInput.autoCapitalize,
  autoFocus?: bool,
  barTintColor?: Color.t,
  cancelButtonText?: string,
  disableBackButtonOverride?: bool,
  hideNavigationBar?: bool,
  hideWhenScrolling?: bool,
  inputType?: inputType,
  obscureBackground?: bool,
  placeholder?: string,
  textColor?: Color.t,
  hintTextColor?: Color.t,
  headerIconColor?: Color.t,
  shouldShowHintSearchIcon?: bool,
  onBlur?: Event.targetEvent => unit,
  onCancelButtonPress?: Event.pressEvent => unit,
  onChangeText?: string => unit,
}

type backOptions = {title?: string}

type gestureDirection = [#vertical | #horizontal]

type rec options = {
  title?: string,
  headerBackButtonMenuEnabled?: bool,
  headerBackVisible?: bool,
  headerBackTitle?: string,
  headerBackTitleVisible?: bool,
  headerBackTitleStyle?: headerBackTitleStyle,
  headerBackImageSource?: string, // TODO
  headerLargeStyle?: headerLargeStyle,
  headerLargeTitle?: bool,
  headerLargeTitleShadowVisible?: bool,
  headerLargeTitleStyle?: headerLargeTitleStyle,
  headerShown?: bool,
  headerStyle?: headerStyle,
  headerShadowVisible?: bool,
  headerTransparent?: bool,
  headerBlurEffect?: blurEffect,
  headerBackground?: Header.headerBackgroundOptions => React.element,
  headerTintColor?: Color.t,
  headerLeft?: Header.headerLeftProps => React.element,
  headerRight?: Header.headerRightProps => React.element,
  headerTitle?: Header.headerTitle,
  headerTitleAlign?: headerTitleAlign,
  headerTitleStyle?: headerTitleStyle,
  headerSearchBarOptions?: headerSearchBarOptions,
  header?: headerParams => React.element,
  statusBarAnimation?: statusBarAnimation,
  statusBarHidden?: bool,
  statusBarStyle?: statusBarStyle,
  statusBarColor?: Color.t,
  statusBarTranslucent?: bool,
  contentStyle?: Style.t,
  customAnimationOnGesture?: bool,
  fullScreenGestureEnabled?: bool,
  gestureEnabled?: bool,
  animationTypeForReplace?: animationTypeForReplace,
  backButtonInCustomView?: bool,
  animation?: animation,
  presentation?: presentation,
  orientation?: orientation,
  autoHideHomeIndicator?: bool,
  gestureDirection?: gestureDirection,
  animationDuration?: float,
  navigationBarColor?: Color.t,
  navigationBarHidden?: bool,
  freezeOnBlur?: bool,
}
and headerParams = {
  navigation: navigation,
  route: route,
  options: options,
  back: backOptions,
}

module type NavigatorModule = {
  module Navigator: {
    @react.component
    let make: (
      ~id: string=?,
      ~initialRouteName: string=?,
      ~screenOptions: screenOptionsParams => options=?,
      ~children: React.element=?,
    ) => React.element
  }

  module Screen: {
    @react.component
    let make: (
      ~name: string,
      ~navigationKey: string=?,
      ~options: screenOptionsParams => options=?,
      ~initialParams: 'params=?,
      ~getId: getIdOptions=?,
      ~component: React.component<screenProps>=?,
      ~getComponent: unit => React.component<screenProps>=?,
      ~children: screenProps => React.element=?,
    ) => React.element
  }

  module Group: {
    @react.component
    let make: (
      ~navigationKey: string=?,
      ~screenOptions: screenOptionsParams => options=?,
    ) => React.element
  }
}

type navigatorModule

%%private(
  @module("@react-navigation/native-stack")
  external createNativeStackNavigator: unit => navigatorModule = "createNativeStackNavigator"

  @module("./Interop")
  external adaptNavigatorModule: navigatorModule => module(NavigatorModule) = "adaptNavigatorModule"
)

module Make = () => unpack(createNativeStackNavigator()->adaptNavigatorModule)

type screenEventData = {closing: int}

module Navigation = {
  @send
  external setOptions: (navigation, options) => unit = "setOptions"

  @send external replace: (navigation, string) => unit = "replace"
  @send
  external replaceWithParams: (navigation, string, 'params) => unit = "replace"

  @send external push: (navigation, string) => unit = "push"
  @send external pushWithParams: (navigation, string, 'params) => unit = "push"

  @send external pop: (navigation, ~count: int=?, unit) => unit = "pop"

  @send external popToTop: (navigation, unit) => unit = "popToTop"

  @send
  external addEventListener: (
    navigation,
    @string
    [
      | #transitionStart(navigationEvent<screenEventData> => unit)
      | #transitionEnd(navigationEvent<screenEventData> => unit)
    ],
  ) => unsubscribe = "addListener"
}
