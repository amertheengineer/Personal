import {createSelector } from 'reselect';
import React, { Component } from 'react';
import {connect} from 'react-redux';


	export default class ActiveTunnelBox extends Component
	{
			constructor(props)
			{
					super(props);
					this.state={
							TunnelName: '',
							TunnelStatus: '',
							TunnelLocation: '',
							hops:0
					}
					// this.displayTunnelName() = this.displayTunnelName.bind(this);
					// this.displayTunnelLocation() = this.displayTunnelLocation.bind(this);
					// this.displayTunnelStatus() = this.displayTunnelStatus.bind(this);
			}

			displayTunnelName()
			{
        return <h1> {this.state.TunnelName} </h1>;
				//this.props.displayTunnelName();
			}
			displayTunnelStatus()
			{
        return <h1> {this.state.TunnelStatus} </h1>;
				//this.props.displayTunnelStatus();
			}
			displayTunnelLocation()
			{
        return <h1> {this.state.TunnelLocation} </h1>;
				//this.props.displayTunnelLocation();
			}
			displayTunnelHops()
			{
					return this.state.hops;
			}
			function displayfield(props)
			{
				for (var i = 0; i < 8; i++) {
					return <option value="TunnelConfig">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
				}
			}
			componentDidMount(props)
			{
				// fetch
					this.setState({
							TunnelName: this.state.TunnelName,
							TunnelStatus:this.state.TunnelStatus
							TunnelLocation:this.state.TunnelLocation,
							hops:this.state.hops
					});
			}

			render()

			{
					return(
						<displayfield />
						/*
	          <select size="8" name="selectionField" multiple="yes">
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          <option value="TunnelName">{this.displayTunnelName()} -- {this.displayTunnelHops()} -- {this.displayTunnelStatus()}    </option>
	          </select>
*/
					);
			}
	}
