# Changelog of `rescript-react-navigation`

## 7.0.3 - 2025-03-05

- Update binding of `tabBarLabel` in BottomTabs and MaterialBottomTabs [#75](https://github.com/rescript-react-native/rescript-react-navigation/pull/75) by @namenu

## 7.0.2 - 2025-02-12

- Screen: fix getId prop [#74](https://github.com/rescript-react-native/rescript-react-navigation/pull/74) by @Freddy03h

## 7.0.1 - 2025-02-02

- MaterialTopTabs: fix sceneStyle [#73](https://github.com/rescript-react-native/rescript-react-navigation/pull/73) by @cknitt

## 7.0.0 - 2025-01-19

- upgrade to `react-navigation` v7 [#72](https://github.com/rescript-react-native/rescript-react-navigation/pull/72) by [Freddy03h](https://github.com/Freddy03h)
  - All changes listed in [Upgrading from 6.x](https://reactnavigation.org/docs/upgrading-from-6.x/)
  - more bindings for `Elements`
  - upgrade to rescript 11.1
  - remove unnecessary trailing unit, and deprecate `___WithParams` functions

## 6.3.0 - 2024-12-23

- Linking [#71](https://github.com/rescript-react-native/rescript-react-navigation/pull/71) by [@Freddy03h](https://github.com/Freddy03h)
- Various fixes and improvements [#69](https://github.com/rescript-react-native/rescript-react-navigation/pull/69) by [@cknitt](https://github.com/cknitt)

## 6.2.0 - 2024-10-20

- added independent param to NavigationContainer [#64](https://github.com/rescript-react-native/rescript-react-navigation/pull/64) by [@witcher-shailesh](https://github.com/witcher-shailesh)
- add methodes on the NavigationContainer ref [9683e14](https://github.com/rescript-react-native/rescript-react-navigation/commit/9683e140d63dccbd14867180a26e58d86f5b65df) by [@Freddy03h](https://github.com/Freddy03h)
- add useHeaderHeight hook to Elements [f7c6190](https://github.com/rescript-react-native/rescript-react-navigation/commit/f7c61906df8d9a09e0372e3a5f12e856619ae634) by [@Freddy03h](https://github.com/Freddy03h)

## 6.1.0 - 2024-04-08

- fix BottomsTabs options type [22db822](https://github.com/rescript-react-native/rescript-react-navigation/commit/22db8227688dd08f7e36810351ca3b646dcb0f1a) by [@Freddy03h](https://github.com/Freddy03h)
- fix some stack header props [9776174](https://github.com/rescript-react-native/rescript-react-navigation/commit/9776174ca6b030f8fcb6b4142d5d41c57519a00d) by [@Freddy03h](https://github.com/Freddy03h)
- Full rewrite for JSX4, records with optional fields + simplicity [#58](https://github.com/rescript-react-native/rescript-react-navigation/pull/58) by [@cknitt](https://github.com/cknitt)
- Add initialLayout prop to MaterialTopTabs Navigator [acbb2ce](https://github.com/rescript-react-native/rescript-react-navigation/commit/acbb2cec4ab7054fa185ed8b79fdd9d0e9dd9a2a) by [@Freddy03h](https://github.com/Freddy03h)

## 6.0.3 - 2022-04-16

- Simplify peerDependencies [df75bda](https://github.com/rescript-react-native/rescript-react-navigation/commit/df75bda) by [@MoOx](https://github.com/MoOx)

## 6.0.2 - 2022-04-13

- Improve stack and material top tabs [b77432d](https://github.com/rescript-react-native/rescript-react-navigation/commit/b77432d) by [@reck753](https://github.com/reck753)

  - Improve `Stack` by adding:
    - `headerBackTestID` screen option
    - `getId` screen prop
  - Add `swipeEnabled` option to `MaterialTopTabs`

## 6.0.1 - 2021-12-06

- Improve `Drawer` bindings [b539ea4](https://github.com/rescript-react-native/rescript-react-navigation/commit/b539ea4) by [@reck753](https://github.com/reck753)
  - add missing options
  - enable creating screen with children (`ScreenWithCallback`)
  - small improvements in existing options

## 6.0.0 - 2021-10-03

- Upgrade to React Navigation 6.0 [9fda4ed](https://github.com/rescript-react-native/rescript-react-navigation/commit/9fda4ed) by [@vknez](https://github.com/vknez)
- Fix `navigateBy*` functions [b89bf1e](https://github.com/rescript-react-native/rescript-react-navigation/commit/b89bf1e) by [@vknez](https://github.com/vknez)

## 5.2.0 - 2021-09-18

- ReScript migration [3a76951](https://github.com/rescript-react-native/rescript-react-navigation/commit/3a76951) by [@cem2ran](https://github.com/cem2ran) & [@Freddy03h](https://github.com/Freddy03h)
- Fix `bottomTabBarProps` instead of `bottomTabBarOptions` [3a76951](https://github.com/rescript-react-native/rescript-react-navigation/commit/3a76951) by [@Freddy03h](https://github.com/Freddy03h)
- Add `materialTopTabBarOptions` and `bottomTabBarOptions` creation functions [3a76951](https://github.com/rescript-react-native/rescript-react-navigation/commit/3a76951) by [@Freddy03h](https://github.com/Freddy03h)

## 5.1.3 - 2021-05-03

ReScript

## 5.1.2 - 2021-02-25

Add missing .res files

## 5.1.1 - 2021-02-25

- Add plenty of missing bindings, (notably ssr, linking, native stack & missing props in stack) [34ff8a8](https://github.com/rescript-react-native/rescript-react-navigation/commit/34ff8a8) by [@MoOx](https://github.com/MoOx)

## 5.1.0 - 2021-02-19

- Breaking changes: rescript 8.2 & rrn 0.63 [757e6b5](https://github.com/rescript-react-native/rescript-react-navigation/commit/757e6b5) by [@MoOx](https://github.com/MoOx)
- Fix NavigationContainer ref [#41](https://github.com/rescript-react-native/rescript-react-navigation/pull/41) by [@dimapaloskin](https://github.com/dimapaloskin)

## 5.0.3 - 2020-11-18

Fix npm description

## 5.0.2 - 2020-09-11

- Fixed missing `src/Interop.js` in npm package [#38](https://github.com/rescript-react-native/rescript-react-navigation/pull/38) by [@baransu](https://github.com/baransu)

## 5.0.1 - 2020-08-20

- Added react ref and key props to components [#37](https://github.com/rescript-react-native/rescript-react-navigation/pull/37) by [@Freddy03h](https://github.com/Freddy03h)

## 5.0.0 - 2020-08-10

- Fixed BottomTabs / MaterialTopTabs tabBar props [#33](https://github.com/rescript-react-native/rescript-react-navigation/pull/33) by [@Freddy03h](https://github.com/Freddy03h)
- Added missing options props for all components [#35](https://github.com/rescript-react-native/rescript-react-navigation/pull/35) by [@Freddy03h](https://github.com/Freddy03h)
- Added ScreenWithCallback for tabs navigators [#34](https://github.com/rescript-react-native/rescript-react-navigation/pull/34) by [@Freddy03h](https://github.com/Freddy03h)
- Added Stack.ScreenWithCallback to support render callback by [@a-c-sreedhar-reddy ](https://github.com/a-c-sreedhar-reddy)
- Upgrade to recent rescript-react-native 0.62, rescript-react 0.9.0 and bs-platform 8 [015c693](https://github.com/rescript-react-native/rescript-react-navigation/commit/015c693) by [@MoOx](https://github.com/MoOx)
  Should still work with previous versions.

## 5.0.0-beta.0 - 2020-02-29

Initial release for 5.x
