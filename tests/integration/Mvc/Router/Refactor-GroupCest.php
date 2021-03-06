<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Router;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Group;
use Phalcon\Mvc\Router\Route;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GroupCest
{
    use DiTrait;

    public function testGroups(IntegrationTester $I)
    {
        Route::reset();
        $router = new Router(false);
        $blog   = new Group(
            [
                'module'     => 'blog',
                'controller' => 'index',
            ]
        );

        $blog->setPrefix('/blog');
        $blog->add(
            '/save',
            [
                'action' => 'save',
            ]
        );
        $blog->add(
            '/edit/{id}',
            [
                'action' => 'edit',
            ]
        );
        $blog->add(
            '/about',
            [
                'controller' => 'about',
                'action'     => 'index',
            ]
        );
        $router->mount($blog);

        $routes = [
            '/blog/save'   => [
                'module'     => 'blog',
                'controller' => 'index',
                'action'     => 'save',
            ],
            '/blog/edit/1' => [
                'module'     => 'blog',
                'controller' => 'index',
                'action'     => 'edit',
            ],
            '/blog/about'  => [
                'module'     => 'blog',
                'controller' => 'about',
                'action'     => 'index',
            ],
        ];

        foreach ($routes as $route => $paths) {
            $router->handle($route);

            $I->assertTrue(
                $router->wasMatched()
            );

            $I->assertEquals(
                $paths['module'],
                $router->getModuleName()
            );

            $I->assertEquals(
                $paths['controller'],
                $router->getControllerName()
            );

            $I->assertEquals(
                $paths['action'],
                $router->getActionName()
            );

            $I->assertEquals(
                $blog,
                $router->getMatchedRoute()->getGroup()
            );
        }
    }

    /**
     * @dataProvider getHostnameRoutes
     */
    public function testHostnameRouteGroup(IntegrationTester $I, Example $example)
    {
        $actualHost   = $example[0];
        $expectedHost = $example[1];
        $controller   = $example[2];

        Route::reset();

        $this->newDi();
        $this->setDiRequest();

        $container = $this->getDi();

        $router = new Router(false);

        $router->setDI($container);

        $router->add(
            '/edit',
            [
                'controller' => 'posts3',
                'action'     => 'edit3',
            ]
        );

        $group = new Group();

        $group->setHostname('my.phalconphp.com');

        $group->add(
            '/edit',
            [
                'controller' => 'posts',
                'action'     => 'edit',
            ]
        );

        $router->mount($group);

        $_SERVER['HTTP_HOST'] = $actualHost;

        $router->handle('/edit');

        $I->assertEquals(
            $controller,
            $router->getControllerName()
        );

        $I->assertEquals(
            $expectedHost,
            $router->getMatchedRoute()->getHostname()
        );
    }

    private function getHostnameRoutes(): array
    {
        return [
            ['localhost', null, 'posts3'],
            ['my.phalconphp.com', 'my.phalconphp.com', 'posts'],
            [null, null, 'posts3'],
        ];
    }

    /**
     * @dataProvider getHostnameRoutesRegex
     */
    public function testHostnameRegexRouteGroup(IntegrationTester $I, Example $example)
    {
        $actualHost   = $example[0];
        $expectedHost = $example[1];
        $controller   = $example[2];

        Route::reset();
        $this->newDi();
        $this->setDiRequest();
        $container = $this->getDi();

        $router = new Router(false);

        $router->setDI($container);

        $router->add(
            '/edit',
            [
                'controller' => 'posts3',
                'action'     => 'edit3',
            ]
        );

        $group = new Group();

        $group->setHostname('([a-z]+).phalconphp.com');

        $group->add(
            '/edit',
            [
                'controller' => 'posts',
                'action'     => 'edit',
            ]
        );

        $router->mount($group);

        $_SERVER['HTTP_HOST'] = $actualHost;

        $router->handle('/edit');

        $I->assertEquals(
            $controller,
            $router->getControllerName()
        );

        $I->assertEquals(
            $expectedHost,
            $router->getMatchedRoute()->getHostname()
        );
    }

    private function getHostnameRoutesRegex(): array
    {
        return [
            ['localhost', null, 'posts3'],
            ['my.phalconphp.com', '([a-z]+).phalconphp.com', 'posts'],
            [null, null, 'posts3'],
        ];
    }
}
