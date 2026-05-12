Banking Management System
A desktop banking app built with C++ and Qt6 for our OOP course project. It supports two types of users (customers and admins), two account types, 2FA login, transaction history, and a bunch of other banking features backed by a local SQLite database.

What it does
As a customer you can:

Register and log in with a hashed password + secret question
Set up two-factor authentication via TOTP (works with Google Authenticator)
Open a savings or current account
Deposit, withdraw, and transfer funds to other users
View and filter your transaction history
Check loan eligibility and convert currencies
Update your profile or request account deletion

As an admin you can:

View all customers and their account balances in one table
Upgrade a customer's tier (Gold , Platinum , Diamond)
Manually deposit or withdraw from any account
Approve or deny account deletion requests

Some banking rules baked in:

Minimum balance is PKR 10,000  drop below it and a PKR 500 penalty is applied once
Daily withdrawal limits depend on tier: Gold 50k, Platinum 200k, Diamond 500k
Savings accounts earn monthly interest
Current accounts allow overdraft up to –PKR 5,000
