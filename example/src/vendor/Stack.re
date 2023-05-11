// https://reactnavigation.org/docs/stack-navigator

open Core;
open Elements;
open ReactNative;

[@bs.deriving jsConverter]
type presentation = [ | `card | `modal | `transparentModal];

[@bs.deriving jsConverter]
type animationTypeForReplace = [ | `push | `pop];

[@bs.deriving jsConverter]
type gestureDirection = [
  | `horizontal
  | [@bs.as "horizontal-inverted"] `horizontal_inverted
  | [@bs.as "vertical-inverted"] `vertical_inverted
];

module TransitionSpec = {
  type t;

  type springConfig = {
    damping: int,
    mass: int,
    stiffness: int,
    restSpeedThreshold: int,
    restDisplacementThreshold: int,
    overshootClamping: bool,
  };

  [@bs.obj]
  external spring: (~animation: [ | `spring], ~config: springConfig) => t;

  type timingConfig = {
    duration: int,
    easing: Easing.t,
  };

  [@bs.obj]
  external timing: (~animation: [ | `timing], ~config: timingConfig) => t;
};

type transitionSpec = {
  open_: TransitionSpec.t,
  close: TransitionSpec.t,
};

type animatedValue = Animated.Value.t;

type layouts = {
  screen: layout,
  title: option(layout),
  leftLabel: option(layout),
};

type interpolation = {progress: animatedValue};

type insets = {
  top: float,
  right: float,
  bottom: float,
  left: float,
};

type headerInterpolationProps = {
  current: interpolation,
  next: option(interpolation),
  layouts,
};

type headerInterpolatedStyle = {
  leftLabelStyle: Style.t,
  leftButtonStyle: Style.t,
  rightButtonStyle: Style.t,
  titleStyle: Style.t,
  backgroundStyle: Style.t,
};

type headerStyleInterpolator =
  headerInterpolationProps => headerInterpolatedStyle;

type cardInterpolationProps = {
  current: interpolation,
  next: option(interpolation),
  index: int,
  closing: animatedValue,
  layouts,
  insets,
};

type cardInterpolatedStyle = {
  containerStyle: Style.t,
  cardStyle: Style.t,
  overlayStyle: Style.t,
  shadowStyle: Style.t,
};

type stackCardStyleInterpolator =
  cardInterpolationProps => cardInterpolatedStyle;

type headerMode = [ | `float | `screen];

type headerBackImageProps = {tintColor: Color.t};

type progress = {
  current: animatedValue,
  next: option(animatedValue),
  previous: option(animatedValue),
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  cardShadowEnabled: bool,
  [@bs.optional]
  cardOverlayEnabled: bool,
  [@bs.optional]
  cardOverlay: unit => React.element,
  [@bs.optional]
  cardStyle: Style.t,
  [@bs.optional]
  presentation,
  [@bs.optional]
  animationEnabled: bool,
  [@bs.optional]
  animationTypeForReplace,
  [@bs.optional]
  gestureEnabled: bool,
  [@bs.optional]
  gestureResponseDistance: float,
  [@bs.optional]
  gestureVelocityImpact: float,
  [@bs.optional]
  gestureDirection,
  [@bs.optional]
  transitionSpec,
  [@bs.optional]
  cardStyleInterpolator: stackCardStyleInterpolator,
  [@bs.optional]
  headerStyleInterpolator,
  [@bs.optional]
  detachPreviousScreen: bool,
  [@bs.optional]
  freezeOnBlur: bool,
  /* TODO: recursive type issue
     [@bs.optional]
     header: headerParams => React.element,
     */
  [@bs.optional]
  headerMode,
  [@bs.optional]
  headerShown: bool,
  [@bs.optional]
  headerBackAllowFontScaling: bool,
  [@bs.optional]
  headerBackAccessibilityLabel: string,
  [@bs.optional]
  headerBackImage: headerBackImageProps,
  [@bs.optional]
  headerBackTitle: string,
  [@bs.optional]
  headerBackTitleVisible: bool,
  [@bs.optional]
  headerTruncatedBackTitle: string,
  [@bs.optional]
  headerBackTitleStyle: Style.t,
  // Header props from https://reactnavigation.org/docs/elements#header
  [@bs.optional]
  headerTitle: Header.headerTitleProps => React.element,
  [@bs.optional]
  headerTitleAlign: Header.headerTitleAlign,
  [@bs.optional]
  headerTitleAllowFontScaling: bool,
  [@bs.optional]
  headerTitleStyle: Style.t,
  [@bs.optional]
  headerTitleContainerStyle: Style.t,
  [@bs.optional]
  headerLeft: Header.headerLeftProps => React.element,
  [@bs.optional]
  headerLeftLabelVisible: bool,
  [@bs.optional]
  headerLeftContainerStyle: Style.t,
  [@bs.optional]
  headerRight: Header.headerRightProps => React.element,
  [@bs.optional]
  headerRightContainerStyle: Style.t,
  [@bs.optional]
  headerPressColor: Color.t,
  [@bs.optional]
  headerPressOpacity: float,
  [@bs.optional]
  headerTintColor: Color.t,
  [@bs.optional]
  headerBackground: Header.headerBackgroundOptions => React.element,
  [@bs.optional]
  headerBackgroundContainerStyle: Style.t,
  [@bs.optional]
  headerTransparent: bool,
  [@bs.optional]
  headerStyle: Style.t,
  [@bs.optional]
  headerShadowVisible: bool,
  [@bs.optional]
  headerStatusBarHeight: Style.size,
};

// TODO: this was a recursive `and` type, but that doesn't work with deriving abstract
type headerParams = {
  navigation,
  route,
  options,
  layout,
  back: headerBackImageProps => React.element,
  styleInterpolator: headerStyleInterpolator,
};

module type NavigatorModule = {
  module Navigator: {
    [@react.component]
    let make:
      (
        ~id: string=?,
        ~initialRouteName: string=?,
        ~screenOptions: screenOptionsParams => options=?,
        ~detachInactiveScreens: bool=?,
        ~keyboardHandlingEnabled: bool=?,
        ~children: React.element=?
      ) =>
      React.element;
  };

  module Screen: {
    [@react.component]
    let make:
      (
        ~name: string,
        ~navigationKey: string=?,
        ~options: screenOptionsParams => options=?,
        ~initialParams: 'params=?,
        ~getId: getIdOptions=?,
        ~component: React.component(screenProps)=?,
        ~getComponent: unit => React.component(screenProps)=?,
        ~children: screenProps => React.element=?
      ) =>
      React.element;
  };

  module Group: {
    [@react.component]
    let make:
      (
        ~navigationKey: string=?,
        ~screenOptions: screenOptionsParams => options=?
      ) =>
      React.element;
  };
};

type navigatorModule;

[@bs.module "@react-navigation/stack"]
external createStackNavigator: unit => navigatorModule =
  "createStackNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (val createStackNavigator()->adaptNavigatorModule);

type screenEventData = {closing: int};

module Navigation = {
  [@bs.send] external setOptions: (navigation, options) => unit = "setOptions";

  [@bs.send] external replace: (navigation, string) => unit = "replace";

  [@bs.send]
  external replaceWithParams: (navigation, string, 'params) => unit =
    "replace";

  [@bs.send] external push: (navigation, string) => unit = "push";

  [@bs.send]
  external pushWithParams: (navigation, string, 'params) => unit = "push";

  [@bs.send] external pop: (navigation, ~count: int=?, unit) => unit = "pop";

  [@bs.send] external popToTop: (navigation, unit) => unit = "popToTop";

  [@bs.send]
  external addEventListener:
    (
      navigation,
      [@bs.string] [
        | `transitionStart(navigationEvent(screenEventData) => unit)
        | `transitionEnd(navigationEvent(screenEventData) => unit)
        | `gestureStart(navigationEvent(unit) => unit)
        | `gestureEnd(navigationEvent(unit) => unit)
        | `gestureCancel(navigationEvent(unit) => unit)
      ]
    ) =>
    unsubscribe =
    "addListener";
};

module TransitionSpecs = {
  // Exact values from UINavigationController's animation configuration
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external transitionIOSSpec: transitionSpec = "TransitionIOSSpec";

  // Configuration for activity open animation from Android Nougat
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external fadeInFromBottomAndroidSpec: transitionSpec =
    "FadeInFromBottomAndroidSpec";

  // Configuration for activity close animation from Android Nougat
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external fadeOutToBottomAndroidSpec: transitionSpec =
    "FadeOutToBottomAndroidSpec";

  // Approximate configuration for activity open animation from Android Pie
  [@bs.module "@react-navigation/stack"] [@bs.scope "TransitionSpecs"]
  external revealFromBottomAndroidSpec: transitionSpec =
    "RevealFromBottomAndroidSpec";
};

module CardStyleInterpolators = {
  // Standard iOS-style slide in from the right
  [@bs.module "react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forHorizontalIOS: stackCardStyleInterpolator = "forHorizontalIOS";

  // Standard iOS-style slide in from the bottom (used for modals)
  [@bs.module "react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forVerticalIOS: stackCardStyleInterpolator = "forVerticalIOS";

  // Standard iOS-style modal animation in iOS 13
  [@bs.module "react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forModalPresentationIOS: stackCardStyleInterpolator =
    "forModalPresentationIOS";

  // Standard Android-style fade in from the bottom for Android Oreo
  [@bs.module "react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forFadeFromBottomAndroid: stackCardStyleInterpolator =
    "forFadeFromBottomAndroid";

  // Standard Android-style reveal from the bottom for Android Pie
  [@bs.module "react-navigation/stack"] [@bs.scope "CardStyleInterpolators"]
  external forRevealFromBottomAndroid: stackCardStyleInterpolator =
    "forRevealFromBottomAndroid";
};

module HeaderStyleInterpolators = {
  // Standard UIKit style animation for the header where the title fades into the back button label
  [@bs.module "react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forUIKit: headerStyleInterpolator = "forUIKit";

  // Simple fade animation for the header elements
  [@bs.module "react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forFade: headerStyleInterpolator = "forFade";

  // Simple translate animation to translate the header along with the sliding screen
  [@bs.module "react-navigation/stack"] [@bs.scope "HeaderStyleInterpolators"]
  external forStatic: headerStyleInterpolator = "forStatic";
};

module TransitionPresets = {
  // Standard iOS navigation transition.
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external slideFromRightIOS: options = "SlideFromRightIOS";

  // Standard iOS navigation transition for modals.
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalSlideFromBottomIOS: options = "ModalSlideFromBottomIOS";

  // Standard iOS modal presentation style (introduced in iOS 13].
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalPresentationIOS: options = "ModalPresentationIOS";

  // Standard Android navigation transition when opening or closing an Activity on Android < 9 (Oreo).
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external fadeFromBottomAndroid: options = "FadeFromBottomAndroid";

  // Standard Android navigation transition when opening or closing an Activity on Android >= 9 (Pie).
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external revealFromBottomAndroid: options = "RevealFromBottomAndroid";

  // Standard Android navigation transition when opening or closing an Activity on Android >= 10
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external scaleFromCenterAndroid: options = "ScaleFromCenterAndroid";

  // Default navigation transition for the current platform.
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external defaultTransition: options = "DefaultTransition";

  // Default modal transition for the current platform.
  [@bs.module "react-navigation/stack"] [@bs.scope "TransitionPresets"]
  external modalTransition: options = "ModalTransition";
};
