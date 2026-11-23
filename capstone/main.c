<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
<title>ParkDesk – Vehicle Parking Management</title>
<link rel="preconnect" href="https://fonts.googleapis.com">
<link href="https://fonts.googleapis.com/css2?family=Barlow+Condensed:wght@600;700&family=Barlow:wght@400;500;600&display=swap" rel="stylesheet">
<style>
:root{--bg:#e6e8e4;--surface:#f6f7f4;--ink:#23272b;--mute:#5d646b;--rule:#c5c9c3;--bay:#1f5fa8;--paint:#e9b923;--free:#2e7d4f;--busy:#b8352b;--asph:#2b2f33;--on-asph:#f1f2ee;color-scheme:light;box-sizing:border-box;padding-top:env(safe-area-inset-top,0px);padding-bottom:env(safe-area-inset-bottom,0px)}
@media (prefers-color-scheme:dark){:root:not([data-theme="light"]){--bg:#1a1d20;--surface:#23282c;--ink:#e8eae6;--mute:#9aa2a9;--rule:#394046;--bay:#6ea6e8;--free:#58b57f;--busy:#ee7b70;--asph:#101214;color-scheme:dark}}
:root[data-theme="dark"]{--bg:#1a1d20;--surface:#23282c;--ink:#e8eae6;--mute:#9aa2a9;--rule:#394046;--bay:#6ea6e8;--free:#58b57f;--busy:#ee7b70;--asph:#101214;color-scheme:dark}
html{scroll-padding-top:env(safe-area-inset-top,0px)}
*,*::before,*::after{box-sizing:border-box}
body{margin:0;background:var(--bg);color:var(--ink);font:400 16px/1.5 Barlow,system-ui,-apple-system,"Segoe UI",sans-serif}
h1,h2,h3{font-family:"Barlow Condensed","Arial Narrow",Impact,sans-serif;font-weight:700;margin:0;letter-spacing:.01em}
.wrap{max-width:1180px;margin:0 auto;padding:0 20px}
header{padding:28px 0 18px;display:flex;flex-wrap:wrap;gap:16px;align-items:flex-end;justify-content:space-between}
h1{font-size:clamp(38px,6vw,60px);line-height:.95}
header p{margin:6px 0 0;color:var(--mute);max-width:46ch}
.stats{display:flex;flex-wrap:wrap;gap:10px}
.stat{background:var(--surface);border:1px solid var(--rule);border-radius:6px;padding:8px 14px;min-width:104px}
.stat b{display:block;font:700 28px/1 "Barlow Condensed",sans-serif}
.stat span{font-size:13px;color:var(--mute)}
.main{display:grid;grid-template-columns:minmax(0,1fr) 330px;gap:20px;align-items:start}
@media(max-width:900px){.main{grid-template-columns:1fr}}
.lot{background:var(--asph);color:var(--on-asph);border-radius:10px;padding:18px 18px 22px}
.zone+.zone{margin-top:20px;padding-top:14px;border-top:3px dashed rgba(241,242,238,.28)}
.zone h2{font-size:22px;margin-bottom:10px;display:flex;justify-content:space-between;gap:10px}
.zone h2 small{font:500 14px Barlow,sans-serif;opacity:.7}
.bays{display:grid;grid-template-columns:repeat(auto-fill,minmax(82px,1fr));gap:0}
.bay{all:unset;box-sizing:border-box;cursor:pointer;height:92px;border-left:3px solid var(--paint);padding:8px 6px;display:flex;flex-direction:column;justify-content:space-between;text-align:center;font-size:12px;overflow:hidden}
.bay:last-child{border-right:3px solid var(--paint)}
.bay .id{font:700 20px "Barlow Condensed",sans-serif}
.bay.free .id{opacity:.85}
.bay.busy{background:rgba(184,53,43,.4)}
.bay.busy .pl{font-weight:600;font-size:11px;line-height:1.15;word-break:break-word}
.bay.free .pl{opacity:.55}
.bay:hover{background:rgba(241,242,238,.12)}
.bay.busy:hover{background:rgba(184,53,43,.55)}
.bay.sel{outline:3px solid #6ea6e8;outline-offset:-3px}
.bay:focus-visible{outline:3px solid #fff;outline-offset:-3px}
.legend{display:flex;gap:16px;margin-top:16px;font-size:13px;opacity:.8;flex-wrap:wrap}
.panel{background:var(--surface);border:1px solid var(--rule);border-radius:10px;padding:18px}
.panel h2{font-size:26px;margin-bottom:12px}
label{display:block;font-size:14px;font-weight:600;margin:12px 0 4px}
input,select{width:100%;font:inherit;color:var(--ink);background:var(--bg);border:1px solid var(--rule);border-radius:6px;padding:9px 10px}
input:focus-visible,select:focus-visible,button:focus-visible{outline:3px solid var(--bay);outline-offset:1px}
.btn{font:600 16px Barlow,sans-serif;border:0;border-radius:6px;padding:11px 16px;cursor:pointer;background:var(--bay);color:#fff;width:100%;margin-top:16px}
.btn.alt{background:var(--busy)}
.btn.sm{width:auto;margin:0;padding:6px 12px;font-size:14px}
.btn.ghost{background:transparent;color:var(--ink);border:1px solid var(--rule)}
.err{color:var(--busy);font-size:14px;margin:10px 0 0;min-height:1.2em}
dl{margin:0;display:grid;grid-template-columns:auto 1fr;gap:6px 14px}
dt{color:var(--mute)}dd{margin:0;font-weight:600;text-align:right}
.fee{font:700 44px/1 "Barlow Condensed",sans-serif;margin:14px 0 0;color:var(--bay)}
section.tbl{margin-top:28px}
section.tbl>div.h{display:flex;flex-wrap:wrap;gap:12px;justify-content:space-between;align-items:center;margin-bottom:10px}
section.tbl h2{font-size:28px}
.search{max-width:260px}
.scroll{overflow-x:auto;background:var(--surface);border:1px solid var(--rule);border-radius:10px}
table{border-collapse:collapse;width:100%;min-width:560px}
th,td{text-align:left;padding:10px 14px;border-bottom:1px solid var(--rule);font-size:15px;white-space:nowrap}
th{font-weight:600;color:var(--mute);font-size:14px}
tr:last-child td{border-bottom:0}
td.empty{color:var(--mute);white-space:normal}
dialog{border:1px solid var(--rule);border-radius:10px;background:var(--surface);color:var(--ink);padding:22px;max-width:360px;width:calc(100% - 32px)}
dialog::backdrop{background:rgba(0,0,0,.5)}
footer{margin:34px 0 28px;color:var(--mute);font-size:14px;display:flex;gap:12px;flex-wrap:wrap;justify-content:space-between}
footer button{font:inherit}
</style>
</head>
<body>
<div class="wrap">
<header>
  <div>
    <h1>ParkDesk</h1>
    <p>Check vehicles in and out, see which bays are free, and collect the right fee every time.</p>
  </div>
  <div class="stats" id="stats"></div>
</header>

<div class="main">
  <div>
    <div class="lot" id="lot"></div>
  </div>
  <aside class="panel" id="panel"></aside>
</div>

<section class="tbl">
  <div class="h"><h2>Parked now</h2><input class="search" id="q" type="search" placeholder="Search plate, owner or bay" aria-label="Search parked vehicles"></div>
  <div class="scroll"><table><thead><tr><th>Plate</th><th>Owner</th><th>Bay</th><th>Checked in</th><th>Time</th><th>Fee so far</th><th></th></tr></thead><tbody id="active"></tbody></table></div>
</section>

<section class="tbl">
  <div class="h"><h2>Recent check-outs</h2></div>
  <div class="scroll"><table><thead><tr><th>Plate</th><th>Bay</th><th>Checked out</th><th>Time</th><th>Fee paid</th></tr></thead><tbody id="hist"></tbody></table></div>
</section>

<footer>
  <span>Rates: cars ₹40 per hour, bikes ₹20 per hour. Part hours are charged as a full hour. Data stays in this browser.</span>
  <button class="btn ghost sm" id="reset">Reset demo data</button>
</footer>
</div>

<dialog id="rcpt"></dialog>

<script>
const RATE={Car:40,Bike:20}, H=36e5;
const slots=[
  ...Array.from({length:12},(_,i)=>({id:'A'+(i+1),type:'Car'})),
  ...Array.from({length:8},(_,i)=>({id:'B'+(i+1),type:'Bike'}))
];
const KEY='parkdesk-v1';
let S=load()||seed(), sel=null, formType='Car', formSlot='', msg='';

function load(){try{return JSON.parse(localStorage.getItem(KEY))}catch(e){return null}}
function save(){try{localStorage.setItem(KEY,JSON.stringify(S))}catch(e){}}
function seed(){
  const n=Date.now();
  return{
    parked:{
      A2:{plate:'TN 09 BQ 4821',owner:'R. Kumar',type:'Car',t:n-2.4*H},
      A5:{plate:'TN 10 CD 7733',owner:'S. Priya',type:'Car',t:n-0.6*H},
      A9:{plate:'KA 03 MN 1290',owner:'A. Fernandes',type:'Car',t:n-5.2*H},
      B3:{plate:'TN 22 EF 5518',owner:'M. Arjun',type:'Bike',t:n-1.3*H}
    },
    history:[{plate:'TN 07 AZ 9902',slot:'A4',type:'Car',t:n-4*H,out:n-1.5*H,fee:120}]
  };
}
const esc=s=>String(s).replace(/[&<>"']/g,c=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c]));
const fee=(p,now)=>Math.max(1,Math.ceil((now-p.t)/H))*RATE[p.type];
const dur=ms=>{const m=Math.max(0,Math.floor(ms/6e4));return Math.floor(m/60)+'h '+String(m%60).padStart(2,'0')+'m'};
const clock=t=>new Date(t).toLocaleTimeString([],{hour:'2-digit',minute:'2-digit'});
const rs=n=>'₹'+n.toLocaleString('en-IN');
const freeOf=type=>slots.filter(s=>s.type===type&&!S.parked[s.id]);

function renderLot(){
  const zones=[['Car','Car bays'],['Bike','Bike bays']];
  document.getElementById('lot').innerHTML=zones.map(([type,title])=>{
    const list=slots.filter(s=>s.type===type), free=list.filter(s=>!S.parked[s.id]).length;
    return `<div class="zone"><h2>${title}<small>${free} of ${list.length} free</small></h2><div class="bays">`+
      list.map(s=>{const p=S.parked[s.id];
        return `<button class="bay ${p?'busy':'free'} ${sel===s.id?'sel':''}" data-slot="${s.id}" aria-label="Bay ${s.id}, ${p?'occupied by '+esc(p.plate):'free'}"><span class="id">${s.id}</span><span class="pl">${p?esc(p.plate):'Free'}</span></button>`}).join('')+
      `</div></div>`}).join('')+
    `<div class="legend"><span>Select a free bay to check a vehicle in.</span><span>Select a red bay to check it out.</span></div>`;
}

function renderStats(){
  const now=Date.now(), start=new Date().setHours(0,0,0,0);
  const earned=S.history.filter(h=>h.out>=start).reduce((a,h)=>a+h.fee,0);
  const items=[[freeOf('Car').length,'Car bays free'],[freeOf('Bike').length,'Bike bays free'],[Object.keys(S.parked).length,'Parked now'],[rs(earned),'Collected today']];
  document.getElementById('stats').innerHTML=items.map(([v,l])=>`<div class="stat"><b>${v}</b><span>${l}</span></div>`).join('');
}

function renderPanel(){
  const el=document.getElementById('panel'), p=sel&&S.parked[sel];
  if(p){
    const now=Date.now();
    el.innerHTML=`<h2>Bay ${sel}</h2><dl><dt>Plate</dt><dd>${esc(p.plate)}</dd><dt>Owner</dt><dd>${esc(p.owner||'Not given')}</dd><dt>Type</dt><dd>${p.type}</dd><dt>Checked in</dt><dd>${clock(p.t)}</dd><dt>Time parked</dt><dd>${dur(now-p.t)}</dd></dl><p class="fee">${rs(fee(p,now))}</p><button class="btn alt" data-out="${sel}">Check out and collect fee</button><button class="btn ghost" data-clear>Close</button>`;
    return;
  }
  if(!formSlot||sel&&!S.parked[sel]){ if(sel){formType=slots.find(s=>s.id===sel).type;formSlot=sel;} }
  const opts=freeOf(formType);
  if(!opts.find(s=>s.id===formSlot)) formSlot=opts[0]?opts[0].id:'';
  el.innerHTML=`<h2>Check in</h2><form id="f" autocomplete="off">
    <label for="pl">Plate number</label><input id="pl" required maxlength="14" placeholder="TN 01 AB 1234" style="text-transform:uppercase">
    <label for="ow">Owner name (optional)</label><input id="ow" maxlength="40">
    <label for="ty">Vehicle type</label><select id="ty"><option ${formType==='Car'?'selected':''}>Car</option><option ${formType==='Bike'?'selected':''}>Bike</option></select>
    <label for="sl">Bay</label><select id="sl">${opts.length?opts.map(s=>`<option ${s.id===formSlot?'selected':''}>${s.id}</option>`).join(''):'<option value="">No free bays</option>'}</select>
    <p class="err" id="err" role="alert">${esc(msg)}</p>
    <button class="btn" type="submit" ${opts.length?'':'disabled'}>Check in vehicle</button></form>`;
  msg='';
}

function renderTables(){
  const now=Date.now(), q=document.getElementById('q').value.trim().toLowerCase();
  const rows=Object.entries(S.parked).filter(([id,p])=>!q||(p.plate+' '+(p.owner||'')+' '+id).toLowerCase().includes(q)).sort((a,b)=>a[1].t-b[1].t);
  document.getElementById('active').innerHTML=rows.length?rows.map(([id,p])=>`<tr><td><b>${esc(p.plate)}</b></td><td>${esc(p.owner||'–')}</td><td>${id}</td><td>${clock(p.t)}</td><td>${dur(now-p.t)}</td><td>${rs(fee(p,now))}</td><td><button class="btn sm" data-out="${id}">Check out</button></td></tr>`).join(''):`<tr><td class="empty" colspan="7">${q?'No parked vehicle matches that search.':'No vehicles parked. Select a free bay to check one in.'}</td></tr>`;
  const hist=S.history.slice(-10).reverse();
  document.getElementById('hist').innerHTML=hist.length?hist.map(h=>`<tr><td><b>${esc(h.plate)}</b></td><td>${h.slot}</td><td>${clock(h.out)}</td><td>${dur(h.out-h.t)}</td><td>${rs(h.fee)}</td></tr>`).join(''):`<tr><td class="empty" colspan="5">Check-outs will appear here.</td></tr>`;
}

function renderAll(){renderLot();renderStats();renderPanel();renderTables()}

function checkout(id){
  const p=S.parked[id]; if(!p) return;
  const out=Date.now(), f=fee(p,out);
  S.history.push({plate:p.plate,slot:id,type:p.type,t:p.t,out,fee:f});
  delete S.parked[id]; save();
  if(sel===id) sel=null;
  const d=document.getElementById('rcpt');
  d.innerHTML=`<h2>Receipt</h2><dl style="margin-top:12px"><dt>Plate</dt><dd>${esc(p.plate)}</dd><dt>Bay</dt><dd>${id}</dd><dt>In</dt><dd>${clock(p.t)}</dd><dt>Out</dt><dd>${clock(out)}</dd><dt>Time</dt><dd>${dur(out-p.t)}</dd></dl><p class="fee">${rs(f)}</p><p style="color:var(--mute);margin:6px 0 0">${p.type} rate ${rs(RATE[p.type])} per hour</p><button class="btn" id="close">Done</button>`;
  d.showModal();
  renderAll();
}

document.addEventListener('click',e=>{
  const b=e.target.closest('[data-slot],[data-out],[data-clear],#close,#reset'); if(!b) return;
  if(b.dataset.slot){sel=b.dataset.slot; const s=slots.find(x=>x.id===sel); if(!S.parked[sel]){formType=s.type;formSlot=sel} renderAll()}
  else if(b.dataset.out) checkout(b.dataset.out);
  else if('clear' in b.dataset){sel=null;renderAll()}
  else if(b.id==='close') document.getElementById('rcpt').close();
  else if(b.id==='reset'){ if(confirm('Replace all data with the demo data?')){S=seed();save();sel=null;renderAll()} }
});
document.addEventListener('change',e=>{
  if(e.target.id==='ty'){formType=e.target.value;formSlot='';sel=null;renderLot();renderPanel()}
  if(e.target.id==='sl'){formSlot=e.target.value;sel=formSlot;renderLot()}
});
document.addEventListener('submit',e=>{
  if(e.target.id!=='f') return; e.preventDefault();
  const plate=document.getElementById('pl').value.trim().toUpperCase().replace(/\s+/g,' ');
  const owner=document.getElementById('ow').value.trim();
  const slot=document.getElementById('sl').value;
  if(!plate||!slot) return;
  if(Object.values(S.parked).some(p=>p.plate===plate)){msg=plate+' is already parked. Check it out first.';renderPanel();return}
  S.parked[slot]={plate,owner,type:formType,t:Date.now()}; save();
  sel=null; formSlot=''; renderAll();
});
document.getElementById('q').addEventListener('input',renderTables);
setInterval(()=>{renderStats();renderTables();if(sel&&S.parked[sel])renderPanel()},30000);
renderAll();
</script>
</body>
</html>
