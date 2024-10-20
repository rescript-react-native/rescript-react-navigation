open ReactNative

module Header = {
  type headerTitleProps = {
    allowFontScaling: option<bool>,
    tintColor: option<Color.t>,
    style: option<Style.t>,
    children: string,
  }

  type headerLeftProps = {
    tintColor: option<Color.t>,
    pressColor: option<Color.t>,
    pressOpacity: option<float>,
    labelVisible: option<bool>,
  }

  type headerRightProps = {
    tintColor: option<Color.t>,
    pressColor: option<Color.t>,
    pressOpacity: option<float>,
  }

  type headerBackgroundOptions = {style: option<Style.t>}

  type headerTitleAlign = [#left | #center]

  @react.component @module("@react-navigation/elements")
  external make: (
    ~title: string=?,
    ~headerTitle: headerTitleProps => React.element=?,
    ~headerTitleAlign: headerTitleAlign=?,
    ~headerTitleAllowFontScaling: bool=?,
    ~headerTitleStyle: Style.t=?,
    ~headerTitleContainerStyle: Style.t=?,
    ~headerLeft: headerLeftProps => React.element=?,
    ~headerLeftLabelVisible: bool=?,
    ~headerLeftContainerStyle: Style.t=?,
    ~headerRight: headerRightProps => React.element=?,
    ~headerRightContainerStyle: Style.t=?,
    ~headerPressColor: Color.t=?,
    ~headerPressOpacity: float=?,
    ~headerTintColor: Color.t=?,
    ~headerBackground: headerBackgroundOptions => React.element=?,
    ~headerBackgroundContainerStyle: Style.t=?,
    ~headerTransparent: bool=?,
    ~headerStyle: Style.t=?,
    ~headerShadowVisible: bool=?,
    ~headerStatusBarHeight: Style.size=?,
  ) => React.element = "Header"
}

module HeaderBackground = {
  @react.component @module("@react-navigation/elements")
  external make: (
    // actually all RN view props
    ~children: React.element=?,
  ) => React.element = "HeaderBackground"
}

module HeaderBackButton = {
  @react.component @module("@react-navigation/elements")
  external make: (
    ~labelVisible: bool=?,
    ~tintColor: Color.t=?,
    ~onPress: unit => unit,
  ) => React.element = "HeaderBackButton"
}

@module("@react-navigation/elements")
external useHeaderHeight: unit => float = "useHeaderHeight"
