import React from 'react';
import {View, Text, requireNativeComponent} from 'react-native';

const AIRMap = requireNativeComponent('AIRMap');

class MapView extends React.Component {
  render() {
    return (
      <View>
        <AIRMap>
          <Text>here</Text>
        </AIRMap>
      </View>
    );
  }
}

export default MapView;
