<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>eewsadm Definitions</title>
    <filename>index</filename>
    <docanchor file="index">eewsadm_bindings</docanchor>
  </compound>
  <compound kind="page">
    <name>eewsadm</name>
    <title>Binding &quot;eewsadm&quot;</title>
    <filename>eewsadm</filename>
    <docanchor file="eewsadm">eewsadm_ports</docanchor>
    <docanchor file="eewsadm">eewsadm_service</docanchor>
    <docanchor file="eewsadm">eewsadm_operations</docanchor>
  </compound>
  <compound kind="struct">
    <name>ns2__getPluginDataResponse</name>
    <filename>structns2____getPluginDataResponse.html</filename>
    <member kind="variable">
      <type>ns2__PluginData *</type>
      <name>pluginData</name>
      <anchorfile>structns2____getPluginDataResponse.html</anchorfile>
      <anchor>70f9d0c7a8e525b4255daec9eb14b9b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ns2__PluginData *</type>
      <name>pluginData</name>
      <anchorfile>structns2____getPluginDataResponse.html</anchorfile>
      <anchor>70f9d0c7a8e525b4255daec9eb14b9b9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ns2__getPluginFieldListResponse</name>
    <filename>structns2____getPluginFieldListResponse.html</filename>
    <member kind="variable">
      <type>PluginFieldList *</type>
      <name>pluginFieldList</name>
      <anchorfile>structns2____getPluginFieldListResponse.html</anchorfile>
      <anchor>1f9710ec51e9eb4c8432d08be8e87608</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>PluginFieldList *</type>
      <name>pluginFieldList</name>
      <anchorfile>structns2____getPluginFieldListResponse.html</anchorfile>
      <anchor>1f9710ec51e9eb4c8432d08be8e87608</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ns2__getPluginListResponse</name>
    <filename>structns2____getPluginListResponse.html</filename>
    <member kind="variable">
      <type>PluginList *</type>
      <name>pluginList</name>
      <anchorfile>structns2____getPluginListResponse.html</anchorfile>
      <anchor>0083b2c87a18f28cac913884556d29f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>PluginList *</type>
      <name>pluginList</name>
      <anchorfile>structns2____getPluginListResponse.html</anchorfile>
      <anchor>0083b2c87a18f28cac913884556d29f3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ns2__getServerConfResponse</name>
    <filename>structns2____getServerConfResponse.html</filename>
    <member kind="variable">
      <type>std::string</type>
      <name>pluginDir</name>
      <anchorfile>structns2____getServerConfResponse.html</anchorfile>
      <anchor>0d9b4882d2b0a18e6003e92a6f4dcebd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>svcPort</name>
      <anchorfile>structns2____getServerConfResponse.html</anchorfile>
      <anchor>0d31adc22bb004da6c9bad1afcd61548</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>admPort</name>
      <anchorfile>structns2____getServerConfResponse.html</anchorfile>
      <anchor>ef0eae49764b48fb2c90268be6236afe</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ns2__PluginData</name>
    <filename>classns2____PluginData.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_type</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>488f1f35d009313eb72dc55c41ccd535</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_default</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>104ce0e9dc389eb049db39528ce9366a</anchor>
      <arglist>(struct soap *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_serialize</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>480c130d926c096a78c59989edfe80db</anchor>
      <arglist>(struct soap *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_put</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>6d031fecad47f1c36691e87252454261</anchor>
      <arglist>(struct soap *, const char *, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_out</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>5d1cc95ce40e3876e00cd4166ff5ef77</anchor>
      <arglist>(struct soap *, const char *, int, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_get</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>8c624f9b96a624fac287a519e8dbbbac</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_in</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>406213bbbf6011c62953a15c029035cf</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>uniqid</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>ee4b448721cd13b338ed888c17beb55c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>desc</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>b7cd83e7b551cae3f4880265ddd47d6b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>version</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>2fd51ec8f8e1b1a4115c873123655e89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>status</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>0bfbadb8a05267ee629c4815c4dbea1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>autoload</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>60c36b10688e6139d0c00c45dbbabd7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>9ff255f10f377c0770ac5844fedfa148</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classns2____PluginData.html</anchorfile>
      <anchor>9ff255f10f377c0770ac5844fedfa148</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ns2__PluginField</name>
    <filename>classns2____PluginField.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_type</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>aaabc63f18eb90f85b2c261936f6c319</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_default</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>c7131372170c642d5b63c86eaf5dbf94</anchor>
      <arglist>(struct soap *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_serialize</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>1943d0a0f2923ccf43464678850579da</anchor>
      <arglist>(struct soap *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_put</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>6a3ad68caa094f54b36e8db7a009e4e3</anchor>
      <arglist>(struct soap *, const char *, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_out</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>5b05ab0b1e08976660b31ea81bc26bca</anchor>
      <arglist>(struct soap *, const char *, int, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_get</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>c8b6e5492481d519625a2cfb416ae4a8</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_in</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>b9ccba442260771754d2a5ba7e8cb617</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>fieldname</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>3e30f875a654bbf637c03284d2736391</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>fieldtype</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>8042b3b176fd4575a2d7b75b469c2085</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>fielddefault</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>094740e83cfd0ca6aabf634c2b3760e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>fieldmin</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>7a1baa9490c60ac9f514740bf7a796fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>fieldmax</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>2f98e6dfed25308a8fd592836a2ffe40</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>9c60bb8a67cc9344b7725719e2f30fb9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classns2____PluginField.html</anchorfile>
      <anchor>9c60bb8a67cc9344b7725719e2f30fb9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ns2__setServerConfResponse</name>
    <filename>structns2____setServerConfResponse.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>pluginDirStatus</name>
      <anchorfile>structns2____setServerConfResponse.html</anchorfile>
      <anchor>a1ec95c03b3d551ccc2963fa7695c1f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>svcPortStatus</name>
      <anchorfile>structns2____setServerConfResponse.html</anchorfile>
      <anchor>ef8eaedb6f964b15fbd920d965dbc02c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>admPortStatus</name>
      <anchorfile>structns2____setServerConfResponse.html</anchorfile>
      <anchor>b73c41c600fb5a7c190bbb8b0c11f379</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ns2__versionResponse</name>
    <filename>structns2____versionResponse.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>id</name>
      <anchorfile>structns2____versionResponse.html</anchorfile>
      <anchor>2c4ce12b51a02907702359cc64a79c1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>desc</name>
      <anchorfile>structns2____versionResponse.html</anchorfile>
      <anchor>cc83969be4e7f64a5cf32321b246714d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>PluginFieldList</name>
    <filename>classPluginFieldList.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_type</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>7e8183be8e13e8672c4e146d9468303d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_default</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>a58dc19bb7478ad7068dc61a4e740e9f</anchor>
      <arglist>(struct soap *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_serialize</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>6aaec26a67cd09c53c489b6a7c8401df</anchor>
      <arglist>(struct soap *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_put</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>fce6bec37db81c46f9b3ff7e2a419b99</anchor>
      <arglist>(struct soap *, const char *, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_out</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>8ad2cf394c9612a6b9318f5790e02ca0</anchor>
      <arglist>(struct soap *, const char *, int, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_get</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>a93d44b89fa6a0e24a08d88ef2f27a87</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_in</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>592e94cb842c1532e5a284a0cf886a73</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="variable">
      <type>ns2__PluginField **</type>
      <name>__ptr</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>8faba492d2ae24a0dc33a76577d6b343</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>__size</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>113a936f7580e5063892b15e24c555dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>1060c8d82fde631151327a677033f265</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ns2__PluginField **</type>
      <name>__ptr</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>3313e5ff8216ef15267cc6a64ccb8ab5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classPluginFieldList.html</anchorfile>
      <anchor>1060c8d82fde631151327a677033f265</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>PluginList</name>
    <filename>classPluginList.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_type</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>b8baf99082bf82d2892d57cd7eb18744</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_default</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>d99b989745f5ba02d19db24543e8ecf1</anchor>
      <arglist>(struct soap *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>soap_serialize</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>5f96753afc9a2fefea19e1e828839fc6</anchor>
      <arglist>(struct soap *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_put</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>d55f399b5f0b4dfa7d2b3b392fe0dd06</anchor>
      <arglist>(struct soap *, const char *, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>soap_out</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>6fedcb6a2fcf66fe25a72b156ff07f71</anchor>
      <arglist>(struct soap *, const char *, int, const char *) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_get</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>4737b6b815b521daeef3ae37d9efa4e9</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>soap_in</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>df521b2378b925ae1784b6f90198798a</anchor>
      <arglist>(struct soap *, const char *, const char *)</arglist>
    </member>
    <member kind="variable">
      <type>ns2__PluginData **</type>
      <name>__ptr</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>629bd47558213f43bd66fe8933e9ebbb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>__size</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>c4f4706c4e0ac0dc340551cc0dfa9b57</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>96ba7bccc56b6dd61651a9c0f85a4cc0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ns2__PluginData **</type>
      <name>__ptr</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>3882efa03a85a2ff8418793712ffc602</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct soap *</type>
      <name>soap</name>
      <anchorfile>classPluginList.html</anchorfile>
      <anchor>96ba7bccc56b6dd61651a9c0f85a4cc0</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
