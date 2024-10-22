# ZCU111 EMIO控制pmod腳位的範例。
##### 開發工具：Vivado2019.1，SDK2019.1，ZCU111開發板與相關資料。
1. 在zynq系列的開發板中有三種GPIO腳位。
    1. MIO   
      腳位直接從PS端拉出，且接線已經固定。
    2. EMIO     
      通過PL部份擴展(拉線的意思)，接到指定腳位。
    3. AXI_GPIO    
      透過AXI界面與PS通訊。
2. 開啟Vivado，在Block design中加入Zynq UltraScale+ MPSoC的IP，並按Run Block Automation採用預設設定，設定好如下圖。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/MPSoC_With_Preset.png"  title="MPSoC with Preset" width="50%"></p>

3. 雙擊MPSoC，將不需要的設定拿掉(下左圖)，也就是PS-PL界面與中斷，並開啟EMIO的功能(下右圖)，在這範例中只需要2個EMIO腳位。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/MPSoC_Setting.png"  title="MPSoC setting" width="50%"></p>   

4. 在MPSoC block的GPIO上按滑鼠右鍵，選擇Make External選項，此時接腳會自動拉出。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Make_External.png"  title="MPSoC gpio make external" width="50%"></p>

5. 將剛剛做的Block design使用Validate Design(f6)確認沒問題。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Validate_Design.png"  title="Validate Design" width="50%"></p>

6. 在Source視窗且Hierarchy下執行Create HDL Wrapper，產出*.v或*.vhd檔案。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Create_HDL_Wrapper.png" title="Create HDL Wrapper" width="30%"></p>

7. 在Constraints目錄上按右鍵，Add Source加入一個約束檔[top.xdc][]，主要的功用是指定EMIO與實際晶片的pin腳有所對應。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Add_Constraints.png" title="Add constraints file" width="30%"></p>

8. 在Flow Navigator的PROGRAM AND DEBUG的項目下，按Generate Bistream，然後發揮耐心等待執行完成。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Generate_Bitstream.png" title="Add constraints file" width="20%"></p>

9. 完成後會跳出一個視窗，請選Open Implemented Design後按OK。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Open_Implemented_Design.png"  title="Open implemented design" width="30%"></p>

10. 主選單File/Export/Export Hardware，Include bitstream選項要勾。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Export_Hardware.png"  title="Export hardware, include bitstream" width="50%"></p>

11. 主選單File/Launch SDK，開啟SDK軟體來寫PS的程式碼。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Launch_SDK.png" title="Launch SDK" width="20%"></p>

12. 步驟11結束後會開啟SDK2019.1，以下操作都在SDK軟體中，首先會看到左方Project Explorer會有步驟10匯出的資料夾，內容名稱不見得一樣。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/SDK_Main_Page.png" title="SDK Main Page" width="50%"></p>

13. 按組合鍵SHIFT+ALT+N，在資料夾上會跑出選單，選擇Application Project，填寫應用程式的名稱，並按Next>。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Applications_Project_Setting.png" title="Applications Project Setting Page" width="50%"></p>

14. 選擇Empty Application，並按Finish。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Empty_Applications.png" title="Empty Application" width="40%"></p>

15. 在所建立的Application Project資料夾裡找到src資料夾，點滑鼠右鍵New一個File取名為[main.c][]。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Create_C_File.png" title="Create C File" width="60%"></p>

16. 可以開始寫PS的程式。

17. 電腦連上FPGA(Jtag)，燒bit檔案到FPGA，Xilinx/Program FPGA，按下Program便會開始燒錄。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Program_FPGA.png" title="Program FPGA" width="60%"></p>

18. 在Application Project資料夾上點滑鼠右鍵，在Run As找到Launch on Hardware(GDB)，點擊就會開始燒入PS程式，並由ZCU111的CPU執行。
<p align=center><img src="https://github.com/weirenxue/zcu111-EMIO/blob/master/pic/Hardware_GDB.png" title="Launch on Hardware(GDB)" width="40%"></p>

  [top.xdc]:https://github.com/weirenxue/zcu111-EMIO/blob/master/code/top.xdc "/code/top.xdc"
  [main.c]:https://github.com/weirenxue/zcu111-EMIO/blob/master/code/main.c "/code/main.c"
