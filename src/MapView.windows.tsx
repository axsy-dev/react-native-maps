import React from 'react';
import {requireNativeComponent} from 'react-native';

const AIRMap = requireNativeComponent('AIRMap');
console.log({AIRMap});

if (!AIRMap) {
  console.warn('No AIRMap');
}

console.log('MapView.windows loaded');

export default function MapView() {
  console.log('Windows MapView');
  return <AIRMap />;
}
