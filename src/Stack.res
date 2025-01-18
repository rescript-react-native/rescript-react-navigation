// https://reactnavigation.org/docs/stack-navigator

open Core
open Elements
open ReactNative

type presentation = [#card | #modal | #transparentModal]

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

type gestureDirection = [#horizontal | #"horizontal-inverted" | #"vertical-inverted"]

module TransitionSpec = {
  type t

  type springConfig = {
    damping: int,
    mass: int,
    stiffness: int,
    restSpeedThreshold: int,
    restDisplacementThreshold: int,
    overshootClamping: bool,
  }

  @obj
  external spring: (~animation: [#spring], ~config: springConfig) => t = ""

  type timingConfig = {
    duration: int,
    easing: Easing.t,
  }

  @obj
  external timing: (~animation: [#timing], ~config: timingConfig) => t = ""
}

type transitionSpec = {
  \"open": TransitionSpec.t,
  close: TransitionSpec.t,
}

type animatedValue = Animated.Value.t

type layouts = {
  screen: layout,
  title: option<layout>,
  leftLabel: option<layout>,
}

type interpolation = {progress: animatedValue}

type insets = {
  top: float,
  right: float,
  bottom: float,
  left: float,
}

type headerInterpolationProps = {
  current: interpolation,
  next: option<interpolation>,
  layouts: layouts,
}

type headerInterpolatedStyle = {
  leftLabelStyle?: Style.t,
  leftButtonStyle?: Style.t,
  rightButtonStyle?: Style.t,
  titleStyle?: Style.t,
  backgroundStyle?: Style.t,
}

type headerStyleInterpolator = headerInterpolationProps => headerInterpolatedStyle

type cardInterpolationProps = {
  current: interpolation,
  next: option<interpolation>,
  index: int,
  closing: animatedValue,
  layouts: layouts,
  insets: insets,
}

type cardInterpolatedStyle = {
  containerStyle?: Style.t,
  cardStyle?: Style.t,
  overlayStyle?: Style.t,
  shadowStyle?: Style.t,
}

type stackCardStyleInterpolator = cardInterpolationProps => cardInterpolatedStyle

type headerMode = [#float | #screen]

type headerBackButtonDisplayMode = [#default | #minimal]

type headerBackImageProps = {tintColor: Color.t}

type progress = {
  current: animatedValue,
  next: option<animatedValue>,
  previous: option<animatedValue>,
}

type rec options = {
  ...Header.headerOptions,
  title?: string,
  cardShadowEnabled?: bool,
  cardOverlayEnabled?: bool,
  cardOverlay?: unit => React.element,
  cardStyle?: Style.t,
  presentation?: presentation,
  animation?: animation,
  animationTypeForReplace?: animationTypeForReplace,
  gestureEnabled?: bool,
  gestureResponseDistance?: float,
  gestureVelocityImpact?: float,
  gestureDirection?: gestureDirection,
  keyboardHandlingEnabled?: bool,
  transitionSpec?: transitionSpec,
  cardStyleInterpolator?: stackCardStyleInterpolator,
  headerStyleInterpolator?: headerStyleInterpolator,
  detachPreviousScreen?: bool,
  freezeOnBlur?: bool,
  header?: headerParams => React.element,
  headerMode?: headerMode,
  headerShown?: bool,
  headerBackAllowFontScaling?: bool,
  headerBackAccessibilityLabel?: string,
  headerBackImage?: headerBackImageProps => React.element,
  headerBackTitle?: string,
  headerBackButtonDisplayMode?: headerBackButtonDisplayMode,
  headerBackTruncatedTitle?: string,
  headerBackTitleStyle?: Style.t,
}
and headerParams = {
  navigation: navigation,
  route: route,
  options: options,
  layout: layout,
  back: headerBackImageProps => React.element,
  styleInterpolator: headerStyleInterpolator,
}

module type NavigatorModule = {
  module Navigator: {
    @react.component
    let make: (
      ~id: string=?,
      ~initialRouteName: string=?,
      ~screenOptions: screenOptionsParams => options=?,
      ~detachInactiveScreens: bool=?,
      ~layout: layoutNavigatorParams => React.element=?,
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
  @module("@react-navigation/stack")
  external createStackNavigator: unit => navigatorModule = "createStackNavigator"

  @module("./Interop")
  external adaptNavigatorModule: navigatorModule => module(NavigatorModule) = "adaptNavigatorModule"
)

module Make = () => unpack(createStackNavigator()->adaptNavigatorModule)

type screenEventData = {closing: int}

module Navigation = {
  @send
  external setOptions: (navigation, options) => unit = "setOptions"

  @send external replace: (navigation, string, ~params: 'params=?) => unit = "replace"
  @deprecated("Use `replace` with `~params` instead") @send
  external replaceWithParams: (navigation, string, 'params) => unit = "replace"

  @send external push: (navigation, string, ~params: 'params=?) => unit = "push"
  @deprecated("Use `push` with `~params` instead") @send
  external pushWithParams: (navigation, string, 'params) => unit = "push"

  @send external pop: (navigation, ~count: int=?, unit) => unit = "pop"

  @send external popTo: (navigation, string, ~params: 'params=?) => unit = "popTo"

  @send external popToTop: (navigation, unit) => unit = "popToTop"

  @send
  external addEventListener: (
    navigation,
    @string
    [
      | #transitionStart(navigationEvent<screenEventData> => unit)
      | #transitionEnd(navigationEvent<screenEventData> => unit)
      | #gestureStart(navigationEvent<unit> => unit)
      | #gestureEnd(navigationEvent<unit> => unit)
      | #gestureCancel(navigationEvent<unit> => unit)
    ],
  ) => unsubscribe = "addListener"
}

module TransitionSpecs = {
  // Exact values from UINavigationController's animation configuration
  @module("@react-navigation/stack") @scope("TransitionSpecs")
  external transitionIOSSpec: transitionSpec = "TransitionIOSSpec"
  // Configuration for activity open animation from Android Nougat
  @module("@react-navigation/stack") @scope("TransitionSpecs")
  external fadeInFromBottomAndroidSpec: transitionSpec = "FadeInFromBottomAndroidSpec"
  // Configuration for activity close animation from Android Nougat
  @module("@react-navigation/stack") @scope("TransitionSpecs")
  external fadeOutToBottomAndroidSpec: transitionSpec = "FadeOutToBottomAndroidSpec"
  // Approximate configuration for activity open animation from Android Pie
  @module("@react-navigation/stack") @scope("TransitionSpecs")
  external revealFromBottomAndroidSpec: transitionSpec = "RevealFromBottomAndroidSpec"
}

module CardStyleInterpolators = {
  // Standard iOS-style slide in from the right
  @module("@react-navigation/stack") @scope("CardStyleInterpolators")
  external forHorizontalIOS: stackCardStyleInterpolator = "forHorizontalIOS"
  // Standard iOS-style slide in from the bottom (used for modals)
  @module("@react-navigation/stack") @scope("CardStyleInterpolators")
  external forVerticalIOS: stackCardStyleInterpolator = "forVerticalIOS"
  // Standard iOS-style modal animation in iOS 13
  @module("@react-navigation/stack") @scope("CardStyleInterpolators")
  external forModalPresentationIOS: stackCardStyleInterpolator = "forModalPresentationIOS"
  // Standard Android-style fade in from the bottom for Android Oreo
  @module("@react-navigation/stack") @scope("CardStyleInterpolators")
  external forFadeFromBottomAndroid: stackCardStyleInterpolator = "forFadeFromBottomAndroid"
  // Standard Android-style reveal from the bottom for Android Pie
  @module("@react-navigation/stack") @scope("CardStyleInterpolators")
  external forRevealFromBottomAndroid: stackCardStyleInterpolator = "forRevealFromBottomAndroid"
}

module HeaderStyleInterpolators = {
  // Standard UIKit style animation for the header where the title fades into the back button label
  @module("@react-navigation/stack") @scope("HeaderStyleInterpolators")
  external forUIKit: headerStyleInterpolator = "forUIKit"
  // Simple fade animation for the header elements
  @module("@react-navigation/stack") @scope("HeaderStyleInterpolators")
  external forFade: headerStyleInterpolator = "forFade"
  // Simple translate animation to translate the header along with the sliding screen
  @module("@react-navigation/stack") @scope("HeaderStyleInterpolators")
  external forStatic: headerStyleInterpolator = "forStatic"
}

module TransitionPresets = {
  // Standard iOS navigation transition.
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external slideFromRightIOS: options = "SlideFromRightIOS"

  // Standard iOS navigation transition for modals.
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external modalSlideFromBottomIOS: options = "ModalSlideFromBottomIOS"

  // Standard iOS modal presentation style (introduced in iOS 13).
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external modalPresentationIOS: options = "ModalPresentationIOS"

  // Standard Android navigation transition when opening or closing an Activity on Android < 9 (Oreo).
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external fadeFromBottomAndroid: options = "FadeFromBottomAndroid"

  // Standard Android navigation transition when opening or closing an Activity on Android >= 9 (Pie).
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external revealFromBottomAndroid: options = "RevealFromBottomAndroid"

  // Standard Android navigation transition when opening or closing an Activity on Android >= 10
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external scaleFromCenterAndroid: options = "ScaleFromCenterAndroid"

  // Default navigation transition for the current platform.
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external defaultTransition: options = "DefaultTransition"

  // Default modal transition for the current platform.
  @module("@react-navigation/stack") @scope("TransitionPresets")
  external modalTransition: options = "ModalTransition"
}
