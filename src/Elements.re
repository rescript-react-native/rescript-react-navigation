open ReactNative;

module Header = {
  type headerTitleProps = {
    allowFontScaling: bool,
    tintColor: Color.t,
    style: Style.t,
    children: string,
  };

  type headerLeftProps = {
    tintColor: Color.t,
    pressColor: Color.t,
    pressOpacity: float,
    labelVisible: bool,
  };

  type headerRightProps = {
    tintColor: Color.t,
    pressColor: Color.t,
    pressOpacity: float,
  };

  type headerBackgroundOptions = {style: option(Style.t)};

  [@bs.deriving jsConverter]
  type headerTitleAlign = [ | `left | `center];

  [@react.component [@bs.module "@react-navigation/elements"]]
  external make:
    (
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
      ~headerStatusBarHeight: Style.size=?
    ) =>
    React.element =
    "Header";
};

module HeaderBackground = {
  [@react.component [@bs.module "@react-navigation/elements"]]
  external make:
    // actually all RN view props
    (~children: React.element=?) =>
    React.element =
    "HeaderBackground";
};

module HeaderBackButton = {
  [@react.component] [@bs.module "@react-navigation/elements"]
  external make:
    (~labelVisible: bool=?, ~tintColor: Color.t=?, ~onPress: unit => unit) =>
    React.element =
    "HeaderBackButton";
};
