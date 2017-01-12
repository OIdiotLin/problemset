#include<cstdio>

char decimals[]="14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196\
44288109756659334461284756482337867831652712019091\
45648566923460348610454326648213393607260249141273\
72458700660631558817488152092096282925409171536436\
78925903600113305305488204665213841469519415116094\
33057270365759591953092186117381932611793105118548\
07446237996274956735188575272489122793818301194912\
98336733624406566430860213949463952247371907021798\
60943702770539217176293176752384674818467669405132\
00056812714526356082778577134275778960917363717872\
14684409012249534301465495853710507922796892589235\
42019956112129021960864034418159813629774771309960\
51870721134999999837297804995105973173281609631859\
50244594553469083026425223082533446850352619311881\
71010003137838752886587533208381420617177669147303\
59825349042875546873115956286388235378759375195778\
18577805321712268066130019278766111959092164201989\
38095257201065485863278865936153381827968230301952\
03530185296899577362259941389124972177528347913151\
55748572424541506959508295331168617278558890750983\
81754637464939319255060400927701671139009848824012\
85836160356370766010471018194295559619894676783744\
94482553797747268471040475346462080466842590694912\
93313677028989152104752162056966024058038150193511\
25338243003558764024749647326391419927260426992279\
67823547816360093417216412199245863150302861829745\
55706749838505494588586926995690927210797509302955\
32116534498720275596023648066549911988183479775356\
63698074265425278625518184175746728909777727938000\
81647060016145249192173217214772350141441973568548\
16136115735255213347574184946843852332390739414333\
45477624168625189835694855620992192221842725502542\
56887671790494601653466804988627232791786085784383\
82796797668145410095388378636095068006422512520511\
73929848960841284886269456042419652850222106611863\
06744278622039194945047123713786960956364371917287\
46776465757396241389086583264599581339047802759009\
94657640789512694683983525957098258226205224894077\
26719478268482601476990902640136394437455305068203\
49625245174939965143142980919065925093722169646151\
57098583874105978859597729754989301617539284681382\
68683868942774155991855925245953959431049972524680\
84598727364469584865383673622262609912460805124388\
43904512441365497627807977156914359977001296160894\
41694868555848406353422072225828488648158456028506\
01684273945226746767889525213852254995466672782398\
64565961163548862305774564980355936345681743241125\
15076069479451096596094025228879710893145669136867\
22874894056010150330861792868092087476091782493858\
90097149096759852613655497818931297848216829989487\
22658804857564014270477555132379641451523746234364\
54285844479526586782105114135473573952311342716610\
21359695362314429524849371871101457654035902799344\
03742007310578539062198387447808478489683321445713\
86875194350643021845319104848100537061468067491927\
81911979399520614196634287544406437451237181921799\
98391015919561814675142691239748940907186494231961\
56794520809514655022523160388193014209376213785595\
66389377870830390697920773467221825625996615014215\
03068038447734549202605414665925201497442850732518\
66600213243408819071048633173464965145390579626856\
10055081066587969981635747363840525714591028970641\
40110971206280439039759515677157700420337869936007\
23055876317635942187312514712053292819182618612586\
73215791984148488291644706095752706957220917567116\
72291098169091528017350671274858322287183520935396\
57251210835791513698820914442100675103346711031412\
67111369908658516398315019701651511685171437657618\
35155650884909989859982387345528331635507647918535\
89322618548963213293308985706420467525907091548141\
65498594616371802709819943099244889575712828905923\
23326097299712084433573265489382391193259746366730\
58360414281388303203824903758985243744170291327656\
18093773444030707469211201913020330380197621101100\
44929321516084244485963766983895228684783123552658\
21314495768572624334418930396864262434107732269780\
28073189154411010446823252716201052652272111660396\
66557309254711055785376346682065310989652691862056\
47693125705863566201855810072936065987648611791045\
33488503461136576867532494416680396265797877185560\
84552965412665408530614344431858676975145661406800\
70023787765913440171274947042056223053899456131407\
11270004078547332699390814546646458807972708266830\
63432858785698305235808933065757406795457163775254\
20211495576158140025012622859413021647155097925923\
09907965473761255176567513575178296664547791745011\
29961489030463994713296210734043751895735961458901\
93897131117904297828564750320319869151402870808599\
04801094121472213179476477726224142548545403321571\
85306142288137585043063321751829798662237172159160\
77166925474873898665494945011465406284336639379003\
97692656721463853067360965712091807638327166416274\
88880078692560290228472104031721186082041900042296\
61711963779213375751149595015660496318629472654736\
42523081770367515906735023507283540567040386743513\
62222477158915049530984448933309634087807693259939\
78054193414473774418426312986080998886874132604721\
56951623965864573021631598193195167353812974167729\
47867242292465436680098067692823828068996400482435\
40370141631496589794092432378969070697794223625082\
21688957383798623001593776471651228935786015881617\
55782973523344604281512627203734314653197777416031\
99066554187639792933441952154134189948544473456738\
31624993419131814809277771038638773431772075456545\
32207770921201905166096280490926360197598828161332\
31666365286193266863360627356763035447762803504507\
77235547105859548702790814356240145171806246436267\
94561275318134078330336254232783944975382437205835\
31147711992606381334677687969597030983391307710987\
04085913374641442822772634659470474587847787201927\
71528073176790770715721344473060570073349243693113\
83504931631284042512192565179806941135280131470130\
47816437885185290928545201165839341965621349143415\
95625865865570552690496520985803385072242648293972\
85847831630577775606888764462482468579260395352773\
48030480290058760758251047470916439613626760449256\
27420420832085661190625454337213153595845068772460\
29016187667952406163425225771954291629919306455377\
99140373404328752628889639958794757291746426357455\
25407909145135711136941091193932519107602082520261\
87985318877058429725916778131496990090192116971737\
27847684726860849003377024242916513005005168323364\
35038951702989392233451722013812806965011784408745\
19601212285993716231301711444846409038906449544400\
61986907548516026327505298349187407866808818338510\
22833450850486082503930213321971551843063545500766\
82829493041377655279397517546139539846833936383047\
46119966538581538420568533862186725233402830871123\
28278921250771262946322956398989893582116745627010\
21835646220134967151881909730381198004973407239610\
36854066431939509790190699639552453005450580685501\
95673022921913933918568034490398205955100226353536\
19204199474553859381023439554495977837790237421617\
27111723643435439478221818528624085140066604433258\
88569867054315470696574745855033232334210730154594\
05165537906866273337995851156257843229882737231989\
87571415957811196358330059408730681216028764962867\
44604774649159950549737425626901049037781986835938\
14657412680492564879855614537234786733039046883834\
36346553794986419270563872931748723320837601123029\
91136793862708943879936201629515413371424892830722\
01269014754668476535761647737946752004907571555278\
19653621323926406160136358155907422020203187277605\
27721900556148425551879253034351398442532234157623\
36106425063904975008656271095359194658975141310348\
22769306247435363256916078154781811528436679570611\
08615331504452127473924544945423682886061340841486\
37767009612071512491404302725386076482363414334623\
51897576645216413767969031495019108575984423919862\
91642193994907236234646844117394032659184044378051\
33389452574239950829659122850855582157250310712570\
12668302402929525220118726767562204154205161841634\
84756516999811614101002996078386909291603028840026\
91041407928862150784245167090870006992821206604183\
71806535567252532567532861291042487761825829765157\
95984703562226293486003415872298053498965022629174\
87882027342092222453398562647669149055628425039127\
57710284027998066365825488926488025456610172967026\
64076559042909945681506526530537182941270336931378\
51786090407086671149655834343476933857817113864558\
73678123014587687126603489139095620099393610310291\
61615288138437909904231747336394804575931493140529\
76347574811935670911013775172100803155902485309066\
92037671922033229094334676851422144773793937517034\
43661991040337511173547191855046449026365512816228\
82446257591633303910722538374218214088350865739177\
15096828874782656995995744906617583441375223970968\
34080053559849175417381883999446974867626551658276\
58483588453142775687900290951702835297163445621296\
40435231176006651012412006597558512761785838292041\
97484423608007193045761893234922927965019875187212\
72675079812554709589045563579212210333466974992356\
30254947802490114195212382815309114079073860251522\
74299581807247162591668545133312394804947079119153\
26734302824418604142636395480004480026704962482017\
92896476697583183271314251702969234889627668440323\
26092752496035799646925650493681836090032380929345\
95889706953653494060340216654437558900456328822505\
45255640564482465151875471196218443965825337543885\
69094113031509526179378002974120766514793942590298\
96959469955657612186561967337862362561252163208628\
69222103274889218654364802296780705765615144632046\
92790682120738837781423356282360896320806822246801\
22482611771858963814091839036736722208883215137556\
00372798394004152970028783076670944474560134556417\
25437090697939612257142989467154357846878861444581\
23145935719849225284716050492212424701412147805734\
55105008019086996033027634787081081754501193071412\
23390866393833952942578690507643100638351983438934\
15961318543475464955697810382930971646514384070070\
73604112373599843452251610507027056235266012764848\
30840761183013052793205427462865403603674532865105\
70658748822569815793678976697422057505968344086973\
50201410206723585020072452256326513410559240190274\
21624843914035998953539459094407046912091409387001\
26456001623742880210927645793106579229552498872758\
46101264836999892256959688159205600101655256375678\
56672279661988578279484885583439751874454551296563\
44348039664205579829368043522027709842942325330225\
76341807039476994159791594530069752148293366555661\
56787364005366656416547321704390352132954352916941\
45990416087532018683793702348886894791510716378529\
02345292440773659495630510074210871426134974595615\
13849871375704710178795731042296906667021449863746\
45952808243694457897723300487647652413390759204340\
19634039114732023380715095222010682563427471646024\
33544005152126693249341967397704159568375355516673\
02739007497297363549645332888698440611964961627734\
49518273695588220757355176651589855190986665393549\
48106887320685990754079234240230092590070173196036\
22547564789406475483466477604114632339056513433068\
44953979070903023460461470961696886885014083470405\
46074295869913829668246818571031887906528703665083\
24319744047718556789348230894310682870272280973624\
80939962706074726455399253994428081137369433887294\
06307926159599546262462970706259484556903471197299\
64090894180595343932512362355081349490043642785271\
38315912568989295196427287573946914272534366941532\
36100453730488198551706594121735246258954873016760\
02988659257866285612496655235338294287854253404830\
83307016537228563559152534784459818313411290019992\
05981352205117336585640782648494276441137639386692\
48031183644536985891754426473998822846218449008777\
69776312795722672655562596282542765318300134070922\
33436577916012809317940171859859993384923549564005\
70995585611349802524990669842330173503580440811685\
52653117099570899427328709258487894436460050410892\
26691783525870785951298344172953519537885534573742\
60859029081765155780390594640873506123226112009373\
10804854852635722825768203416050484662775045003126\
20080079980492548534694146977516493270950493463938\
24322271885159740547021482897111777923761225788734\
77188196825462981268685817050740272550263329044976\
27789442362167411918626943965067151577958675648239\
93917604260176338704549901761436412046921823707648\
87834196896861181558158736062938603810171215855272\
66830082383404656475880405138080163363887421637140\
64354955618689641122821407533026551004241048967835\
28588290243670904887118190909494533144218287661810\
31007354770549815968077200947469613436092861484941\
78501718077930681085469000944589952794243981392135\
05586422196483491512639012803832001097738680662877\
92397180146134324457264009737425700735921003154150\
89367930081699805365202760072774967458400283624053\
46037263416554259027601834840306811381855105979705\
66400750942608788573579603732451414678670368809880\
60971642584975951380693094494015154222219432913021\
73912538355915031003330325111749156969174502714943\
31515588540392216409722910112903552181576282328318\
23425483261119128009282525619020526301639114772473\
31485739107775874425387611746578671169414776421441\
11126358355387136101102326798775641024682403226483\
46417663698066378576813492045302240819727856471983\
96308781543221166912246415911776732253264335686146\
18654522268126887268445968442416107854016768142080\
88502800541436131462308210259417375623899420757136\
27516745731891894562835257044133543758575342698699\
47254703165661399199968262824727064133622217892390\
31760854289437339356188916512504244040089527198378\
73864805847268954624388234375178852014395600571048\
11949884239060613695734231559079670346149143447886\
36041031823507365027785908975782727313050488939890\
09923913503373250855982655867089242612429473670193\
90772713070686917092646254842324074855036608013604\
66895118400936686095463250021458529309500009071510\
58236267293264537382104938724996699339424685516483\
26113414611068026744663733437534076429402668297386\
52209357016263846485285149036293201991996882851718\
39536691345222444708045923966028171565515656661113\
59823112250628905854914509715755390024393153519090\
21071194573002438801766150352708626025378817975194\
78061013715004489917210022201335013106016391541589\
57803711779277522597874289191791552241718958536168\
05947412341933984202187456492564434623925319531351\
03311476394911995072858430658361935369329699289837\
91494193940608572486396883690326556436421664425760\
79147108699843157337496488352927693282207629472823\
81537409961545598798259891093717126218283025848112\
38901196822142945766758071865380650648702613389282\
29949725745303328389638184394477077940228435988341\
00358385423897354243956475556840952248445541392394\
10001620769363684677641301781965937997155746854194\
63348937484391297423914336593604100352343777065888\
67781139498616478747140793263858738624732889645643\
59877466763847946650407411182565837887845485814896\
29612739984134427260860618724554523606431537101127\
46809778704464094758280348769758948328241239292960\
58294861919667091895808983320121031843034012849511\
62035342801441276172858302435598300320420245120728\
72535581195840149180969253395075778400067465526031\
44616705082768277222353419110263416315714740612385\
04258459884199076112872580591139356896014316682831\
76323567325417073420817332230462987992804908514094\
79036887868789493054695570307261900950207643349335\
91060245450864536289354568629585313153371838682656\
17862273637169757741830239860065914816164049449650\
11732131389574706208847480236537103115089842799275\
44268532779743113951435741722197597993596852522857\
45263796289612691572357986620573408375766873884266\
40599099350500081337543245463596750484423528487470\
14435454195762584735642161981340734685411176688311\
86544893776979566517279662326714810338643913751865\
94673002443450054499539974237232871249483470604406\
34716063258306498297955101095418362350303094530973\
35834462839476304775645015008507578949548931393944\
89921612552559770143685894358587752637962559708167\
76438001254365023714127834679261019955852247172201\
77723700417808419423948725406801556035998390548985\
72354674564239058585021671903139526294455439131663\
13453089390620467843877850542393905247313620129476\
91874975191011472315289326772533918146607300089027\
76896311481090220972452075916729700785058071718638\
10549679731001678708506942070922329080703832634534\
52038027860990556900134137182368370991949516489600\
75504934126787643674638490206396401976668559233565\
46391383631857456981471962108410809618846054560390\
38455343729141446513474940784884423772175154334260\
30669883176833100113310869042193903108014378433415\
13709243530136776310849135161564226984750743032971\
67469640666531527035325467112667522460551199581831\
96376370761799191920357958200759560530234626775794\
39363074630569010801149427141009391369138107258137\
81357894005599500183542511841721360557275221035268\
03735726527922417373605751127887218190844900617801\
3889710770822931002797665935838758";

int main()
{
	int N;
	scanf("%d",&N);
	freopen("Pi.in","r",stdin);
	freopen("Pi.out","w",stdout);
	printf("PI=3.\n\n");
	for(int i=0;i<N;i++)
	{
		printf("%c",decimals[i]);
	}
	return 0;
}
