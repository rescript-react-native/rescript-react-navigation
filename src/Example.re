module HomeScreen = {
  open ReactNative;
  [@react.component]
  let make = (~navigation, ~route) =>
    <Text> {j|Hello Reasonable Person!|j}->React.string </Text>;
};

module ModalScreen = {
  open ReactNative;
  [@react.component]
  let make = (~navigation, ~route) =>
    <Text> {j|Hello From Modal|j}->React.string </Text>;
};

module MainStackScreen = {
  open ReactNative;
  module StakeParams = {
    type params = {name: string};
  };
  include Stack.Make(StakeParams);
  [@react.component]
  let make = (~navigation, ~route) =>
    <Navigator>
      <Screen
        name="Home"
        component=HomeScreen.make
        options={props =>
          options(
            ~headerRight=
              _ =>
                <Button
                  onPress={_ =>
                    props.navigation->Navigation.navigate("MyModal")
                  }
                  title="Info"
                  color="#f00"
                />,
            ~title=
              switch (props.route.params) {
              | Some(params) => params.name
              | None => "Reason"
              },
            (),
          )
        }
      />
    </Navigator>;
};

module RootStackScreen = {
  include Stack.Make({
    type params = unit;
  });
  [@react.component]
  let make = () =>
    <Native.NavigationContainer>
      <Navigator mode=`modal headerMode=`none>
        <Screen name="Main" component=MainStackScreen.make />
        <Screen name="MyModal" component=ModalScreen.make />
      </Navigator>
    </Native.NavigationContainer>;
};
