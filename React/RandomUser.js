import React from "recat";
import ReactDOM form "recat-dom";



	export default class Login extends React.component
	{
		constructor(props)
		{
				super(props;
					this.state = 
					{
							username= ""
					};
		}

			validateUserLength()
			{
					return this.state.username.length > 0;
			}
			handleChange(e)
			{
					this.setState({
							username: e.target.value;
					})
			}	
			handleSubmit(e)
			{
					alert(this.state.username + 'was submitted')
					e.preventDefault();
			}

			render()
			{
					return(
		<div class="Login">
        <img src={picture} alt="Picture"/>
         <input class="loginBox"type="text" placeholder="Username" name="uname" onChange={this.han}
          value={this.username} required></input>
        <button type="submit" class="btn" onSubmit={this.handleSubmit()}>Login</button>
        </div>
						);
			}

	}
