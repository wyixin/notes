<html>
{if a === 1}
<h1>One</h1>
{else if b === 2}
<h1>One</h1>
<h1>Two</h1>
{else}
<h1>One</h1>
<h1>Two</h1>
<h1>Three</h1>
{/if}
{data}
{loop users}
<h1>{V}</h1>
{/loop}
{loop students}
<h1>{K}</h1>
{/loop}
</html>
