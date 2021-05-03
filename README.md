# `rescript-react-navigation`

[![Build Status](https://github.com/rescript-react-native/rescript-react-navigation/workflows/Build/badge.svg)](https://github.com/rescript-react-native/rescript-react-navigation/actions)
[![Version](https://img.shields.io/npm/v/rescript-react-navigation.svg)](https://www.npmjs.com/rescript-react-navigation)
[![ReScript Forum](https://img.shields.io/discourse/posts?color=e6484f&label=ReScript%20Forum&server=https%3A%2F%2Fforum.rescript-lang.org)](https://forum.rescript-lang.org/)

[ReScript](https://rescript-lang.org) bindings for
[`react-navigation`](https://github.com/react-navigation/react-navigation).

Exposed as `ReactNavigation` module.

`rescript-react-navigation` X.y.\* means it's compatible with `react-navigation`
X.y.\*

## Status

⚠️ Work in progress. These bindings are used successfully in several apps, but
are not complete yet and still subject to change.

## Installation

When
[`react-navigation`](https://github.com/react-navigation/react-navigation) is
properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install rescript-react-navigation
# or
yarn add rescript-react-navigation
```

`rescript-react-navigation` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "@rescript/react",
    "rescript-react-native",
    // ...
+    "rescript-react-navigation"
  ],
  //...
}
```

## Example

See <./src/Example.re>

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

## Contribute

Read the [contribution guidelines](https://github.com/rescript-react-native/.github/blob/master/CONTRIBUTING.md) before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/rescript-react-native/.github/blob/master/CODE_OF_CONDUCT.md) so that you can understand what
actions will and will not be tolerated.
