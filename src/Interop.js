// Adapt the result of createXxxNavigator to return a module in the shape that ReScript expects.
// Navigator and Screen are escaped with `$$` prefix by ReScript.

export function adaptNavigatorModule(m) {
  return {
    $$Navigator: { make: m.Navigator },
    $$Screen: { make: m.Screen },
    Group: { make: m.Group },
  };
}
