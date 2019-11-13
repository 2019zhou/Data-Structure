# writing code and debugging code during the process of queue_simulation
- 1. 最大的错误在于自己对于队列的定义没有定义的很好，rear对应的是银行队伍中前面来的人，front对应的是银行中后面来的人
- 2. rear, front两个值的设置，这里选择的是rear填入数据，而front不填入数据
- 3. 还有关于存储，自己的存储是用了两个单元，两个单元存储的，这样可能没有普适和扩展性。
